#include<bits/stdc++.h>
using namespace std;
struct pp{
	int a,b,c;
}a[100005];
bool cmp(pp x,pp y){
	if(x.a!=y.a)return x.a>y.a;
	else if(x.b!=y.b)return x.b>y.b;
	else return x.c>y.c;
}
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag=false,ss=false;
		int x=n/2,w=0,q=0;
		int sum[100005]={0};
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==0&&a[i].c==0)flag=1;
			else flag=0;
			if(flag==0)ss=1;
		}
		sort(a+1,a+1+n,cmp);
		if(ss!=1){
			for(int i=1;i<=x;i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
			break;
		}
		if(n==2){
			int p=a[1].a +a[2].b ;
			int o=max(p,a[1].a +a[2].c);
			int u=max(o,a[1].b +a[2].a );
			int y=max(u,a[1].b +a[2].c );
			int t=max(y,a[1].c +a[2].a );
			int r=max(t,a[1].c +a[2].b );
			cout<<r<<endl;
			break;
		}
		for(int i=1;i<=n;i++){
			int maxx=max(a[i].a,a[i].b);
			if(maxx==a[i].a)w=1;
			else w=2;
			int maxn=max(maxx,a[i].c);
			if(maxn==maxx)q=w;
			else q=3;
			if(q==3&&sum[q]<x){
				sum[q]++;
				ans+=a[i].c;
			}
			else if(q==2&&sum[q]<x){
				sum[2]++;
				ans+=a[i].b;
			}
			else {
				sum[1]++;
				ans+=a[i].a;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
