#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int N=1e5+5;
//int a[N],b[N],c[N];
int sum[5],cnt[5];
struct node{
	int a,b,c;
//	int dab,dac,dbc;
	int mx,sc,d;
	bool operator <(const node &x)const{
		return x.d<d;
	}
};
priority_queue<node>q[5];
node f[N];
//int g[305][305][305];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
			int tr1=max(f[i].a,max(f[i].b,f[i].c)),tr3=min(f[i].a,min(f[i].b,f[i].c));
			int tr2=f[i].a+f[i].b+f[i].c-tr1-tr3;
			f[i].d=tr1-tr2;
			int r1=f[i].a,r2=f[i].b,r3=f[i].c;
			if(tr1==r1)f[i].mx=1;
			if(tr1==r2)f[i].mx=2;
			if(tr1==r3)f[i].mx=3;
			if(tr2==r1)f[i].sc=1;
			if(tr2==r2)f[i].sc=2;
			if(tr2==r3)f[i].sc=3;
//			f[i].dab=f[i].a-f[i].b;
//			f[i].dbc=f[i].b-f[i].c;
//			f[i].dac=f[i].a-f[i].c;
//			if(f[i].dab<0)f[i].dab=-f[i].dab;
//			if(f[i].dbc<0)f[i].dbc=-f[i].dbc;
//			if(f[i].dac<0)f[i].dac=-f[i].dac;
		}
//		for(int i=1;i<=n;i++){
//			cout<<f[i].mx<<" "<<f[i].sc<<" "<<f[i].d<<"\n";
//		}
		int mxl=n/2;
//		cout<<mxl<<" mxl\n";
		long long maxn=0;
		for(int i=1;i<=n;i++){
			int r1=f[i].mx,r2=f[i].sc;
			if(cnt[r1]<mxl){
//				cout<<i<<" KKK\n";
//				sum[r1]+=f[i].a;
				cnt[r1]++;
				q[r1].push(f[i]);
			}
			else{
				node k=q[r1].top();
				
				if(f[i].d<k.d){
					cnt[r2]++;
					q[r2].push(f[i]);
				}
				
				else{
					q[r1].pop();
//					sum[r1]+=f[i].a;
//					cnt[r1]++;
					q[r1].push(f[i]);
//					sum[r1]-=k.a;
//					sum[k.sc]+=k.
					cnt[k.sc]++;
					q[k.sc].push(k);
				}
			}
		}
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				node k=q[i].top();
				q[i].pop();
				if(i==1){
//					cout<<k.a<<" qwqa\n";
					maxn+=k.a;
				}
				else if(i==2){
//					cout<<k.b<<" qwqb\n";
					maxn+=k.b;
				}
				else{
//					cout<<k.c<<" qwqc\n";
					maxn+=k.c;
				}
			}
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		cout<<maxn<<"\n";
	}
	return 0;
}
