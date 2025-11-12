#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct f{
	ll l,m,r;
}a[200010];
int cmp(f o,f p)
{
	ll x=max(max(o.l,o.m),o.r);
	ll y=max(max(p.l,p.m),p.r);
	return x>=y;
}
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&T);	
	while(T--)	{
		ll ans=0;
		ll n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].m>>a[i].r;
		ll num=n/2;
		sort(a+1,a+n+1,cmp);
		ll x=num,y=num,z=num;					
		for(int i=2;i<=n;i++){			
			int best=max(max(a[i].l,a[i].m),a[i].r);			
			int sdw;
			if(max(max(a[i].l,a[i].m),a[i].r)==a[i].l){
				sdw=x;
			}
			else if(max(max(a[i].l,a[i].m),a[i].r)==a[i].m){
				sdw=y;
			}
			else if(max(max(a[i].l,a[i].m),a[i].r)==a[i].r){
				sdw=z;
			}			
			if(max(max(best+a[i-1].l,best+a[i-1].m),best+a[i-1].r)==a[i-1].l+best){
				if(x-1>0){
					ans+=a[i-1].l;
					x--;					
				}
				if(ans+a[i-1].l>ans+a[i-1].m+best&&ans+a[i-1].l>ans+a[i-1].r+best&&x>0){
					ans+=a[i-1].l;
					x--;
				}			
				else if(max(best+a[i-1].m,best+a[i-1].r)==a[i-1].m+best&&y>0||z==0&&y>0){
					ans+=a[i-1].m;
					y--;
				}
				else{
					ans+=a[i-1].r;
					z--;
				}
			}						
			else if(max(max(best+a[i-1].l,best+a[i-1].m),best+a[i-1].r)==a[i-1].m+best){
				if(y-1>0){
					ans+=a[i-1].m;
					y--;					
				}
				if(ans+a[i-1].m>ans+a[i-1].r+best&&ans+a[i-1].m>ans+a[i-1].l+best&&y>0){
					ans+=a[i-1].m;
					y--;
				}			
				else if(max(best+a[i-1].l,best+a[i-1].r)==a[i-1].l+best&&x>0||z==0&&x>0){
					ans+=a[i-1].l;
					x--;
				}
				else{
					ans+=a[i-1].r;
					z--;
				}
			}			
			else if(max(max(best+a[i-1].l,best+a[i-1].m),best+a[i-1].r)==a[i-1].r+best){
				if(z-1>0){
					ans+=a[i-1].r;
					z--;					
				}
				if(ans+a[i-1].r>ans+a[i-1].m+best&&ans+a[i-1].r>ans+a[i-1].l+best&&z>0){
					ans+=a[i-1].r;
					z--;
				}			
				else if(max(best+a[i-1].m,best+a[i-1].m)==a[i-1].m+best&&y>0||x==0){
					ans+=a[i-1].m;
					y--;
				}
				else{
					ans+=a[i-1].r;
					x--;
				}
			}			
			if(i==n&&sdw-1>=0){
				ans+=best;	
			}				
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i].l=0;
			a[i].m=0;
			a[i].r=0;
		}		
	}	
	return 0;
 } 
