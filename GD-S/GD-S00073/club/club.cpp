#include<bits/stdc++.h>

using namespace std;

int t,n,res,clubs[3],m; 

struct Ns{
	int a,b,c,clu;
}lst[100010];

bool cmp1(Ns x1,Ns x2){
	if(m = 0)  return max(x1.b-x1.a,x1.c-x1.a)>max(x2.b-x2.a,x2.c-x2.a);
	else if(m = 1) return  max(x1.c-x1.b,x1.a-x1.b)>max(x2.a-x2.b,x2.c-x2.b);
	else return  max(x1.b-x1.c,x1.a-x1.c)>max(x2.b-x2.c,x2.a-x2.c);
}
bool cmp2(Ns x1,Ns x2){
	return x2.clu>x1.clu;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i =0;i<t;i++){
		clubs[0]=0;
		clubs[1]=0;
		clubs[2] =0;
		res = 0;
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>lst[j].a>>lst[j].b>>lst[j].c;
			if(lst[j].a>=lst[j].b&&lst[j].a>=lst[j].c) {
				lst[j].clu=0;
				res+=lst[j].a;
			}
			else if(lst[j].b>=lst[j].a&&lst[j].b>=lst[j].c) {
				lst[j].clu=1;
				res+=lst[j].b;
			}
			else  {
				lst[j].clu =2;
				res+=lst[j].c;
			}
			clubs[lst[j].clu]++;			
		}
		if(clubs[0]>=clubs[2]&&clubs[0]>=clubs[1]) m=0;
		else if(clubs[1]>=clubs[2]&&clubs[1]>=clubs[0]) m=1;
		else m=2;
		sort(lst+1,lst+1+n,cmp2);
		
		if(m == 0){
			sort(lst+1,lst+1+clubs[0],cmp1);
			for(int j = 1;j<=clubs[m]-(n/2);j++){
				res+=max(lst[j].b-lst[j].a,lst[j].c-lst[j].a);
			}
		}else if(m==1) {
			sort(lst+1+clubs[0],lst+1+clubs[1],cmp1);
			for(int j = 1+clubs[0];j<=clubs[0]+clubs[m]-(n/2);j++){
				res+=max(lst[j].c-lst[j].b,lst[j].a-lst[j].b);
			}
		}else{
			sort(lst+1+clubs[0]+clubs[1],lst+1+n,cmp1);
			for(int j = 1+clubs[0]+clubs[1];j<=clubs[1]+clubs[0]+clubs[m]-(n/2);j++){
				res+= max(lst[j].b-lst[j].c,lst[j].a-lst[j].c);
			}
		}
		
		
		cout<<res<<endl;
	}
}
