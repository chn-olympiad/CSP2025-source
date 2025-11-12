#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][10],cnm,flag1[N],flag2[N];
struct tere{
	int id,num;
}b[N],c[N];
bool cmp(tere x,tere y){
	return x.num>y.num;
}
void check(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j==1){
				b[i].id=i;
				b[i].num=a[i][j];
			}
			if(j==2){
				c[i].id=i;
				c[i].num=a[i][j];
			}
		} 
	}
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
	int sum=0,cnm=0;
	for(int i=1;i<=n/2;i++){
		sum+=b[i].num;
		cnm+=c[i].num;
		flag1[b[i].id]=1; 
		flag2[b[i].id]=1;
	}
	for(int i=1;i<=n;i++){
		if(flag1[i]==0){
			sum+=c[i].num;
		}
		if(flag2[i]==0){
			cnm+=b[i].num;
		}
	}cout<<max(sum,cnm)<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[i][j]=0;
		}b[i].num=0;b[i].id=0;
		c[i].num=0;c[i].id=0;
		flag1[i]=0;
		flag2[i]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		check();
	}
	return 0;
} 
