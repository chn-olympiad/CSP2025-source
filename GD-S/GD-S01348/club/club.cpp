#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
struct P{
	int a,b,c,val;
}d[N],f[N];
bool cmp(P x,P y){
	return x.val>y.val;
}
int n;
int ans,sum;
void calc(){
	sum=0;
	int cnta=0,cntb=0,cntc=0;
	for(int i=1;i<=n;i++){
		if(d[i].val<=0||cnta==n/2)break;
		sum+=d[i].a,cnta++;
	}
	for(int i=cnta+1;i<=n;i++)
		d[i].val=d[i].b-max(d[i].a,d[i].c);
	sort(d+cnta+1,d+n+1,cmp);
	for(int i=cnta+1;i<=n;i++){
		if(cntb<n/2&&d[i].val>0)
			sum+=d[i].b,cntb++;
		else if(cntb==n/2)
			sum+=max(d[i].a,d[i].c);
		else{
			if(cnta==n/2)sum+=d[i].c;
			else if(cntc==n/2)sum+=d[i].a;
			else{
				if(d[i].a>=d[i].c)sum+=d[i].a,cnta++;
				else sum+=d[i].c,cntc++;
			}
		}
	}
	ans=max(ans,sum);
	return;
}
void solve(){
	int x,y,z;
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>d[i].a>>d[i].b>>d[i].c,f[i]=d[i],d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	//acb
	for(int i=1;i<=n;i++)
		d[i].a=f[i].a,d[i].b=f[i].c,d[i].c=f[i].b,d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	//bac
	for(int i=1;i<=n;i++)
		d[i].a=f[i].b,d[i].b=f[i].a,d[i].c=f[i].c,d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	//bca
	for(int i=1;i<=n;i++)
		d[i].a=f[i].b,d[i].b=f[i].c,d[i].c=f[i].a,d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	//cab
	for(int i=1;i<=n;i++)
		d[i].a=f[i].c,d[i].b=f[i].a,d[i].c=f[i].b,d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	//cba
	for(int i=1;i<=n;i++)
		d[i].a=f[i].c,d[i].b=f[i].b,d[i].c=f[i].a,d[i].val=d[i].a-max(d[i].b,d[i].c);
	sort(d+1,d+n+1,cmp);calc();
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
} 
