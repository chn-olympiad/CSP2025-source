#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}d[N];
int T,n,bumen1,bumen2,bumen3,renshu1,renshu2,renshu3,touru=-1e9;
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return (x.a+x.b+x.c)>(y.a+y.b+y.c);
}
void dfs(int dep,int wenben1,int wenben2,int wenben3,int saoma){
	if(dep==n){
		touru=max(touru,saoma);
		return;
	}
	if(wenben1+1<=n/2)dfs(dep+1,wenben1+1,wenben2,wenben3,saoma+d[dep].a);
	if(wenben2+1<=n/2)dfs(dep+1,wenben1,wenben2+1,wenben3,saoma+d[dep].b);
	if(wenben3+1<=n/2)dfs(dep+1,wenben1,wenben2,wenben3+1,saoma+d[dep].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		bumen1=0,bumen2=0,bumen3=0;
		renshu1=0,renshu2=0,renshu3=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
		if(d[1].c==0 && d[1].b==0 && d[0].b==0 && d[0].c==0){
			sort(d,d+n,cmp1);
			for(int i=0;i<n;i++)cout<<d[i].a<<endl;
			for(int i=0;renshu1<n/2;i++){
				bumen1+=d[i].a;
				renshu1++;
			}
			cout<<bumen1<<endl;
		}else if(n==2){
			int o=d[0].a+d[1].b,p=d[0].a+d[1].c,q=d[0].b+d[1].a,r=d[0].b+d[1].c,s=d[0].c+d[1].b,t=d[0].c+d[1].a;
			cout<<max(o,max(p,max(q,max(r,t))))<<endl;
		}
		else if(d[1].c<=3 && d[0].c<=3 && d[2].c<=3){
			sort(d,d+n,cmp1);
			for(int i=0;i<n/2;i++)bumen1+=d[i].a;
			for(int i=n/2;i<n;i++)bumen2+=d[i].b;
			cout<<(bumen1+bumen2)<<endl;
		}
		else{
			dfs(0,0,0,0,0);
			cout<<touru<<endl;	
		}
	}
	return 0;
} 
