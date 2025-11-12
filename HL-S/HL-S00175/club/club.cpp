#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct Node{
	int l,m,r,fi,se,lt,fid,sed,ltd;
}p[5000010];
int cnt[4];
bool cmp(Node a,Node b){
	return a.fi>b.fi;
	if(a.fi==b.fi) return a.se>b.se;
	else return a.lt>b.lt;
}
signed main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].l>>p[i].m>>p[i].r;
			int x=p[i].l;
			int y=p[i].m;
			int z=p[i].r;
			p[i].fi=max(x,max(y,z));
			p[i].lt=min(x,min(y,z));
			
			if(x==p[i].fi){
			    p[i].fid=1;
			    if(y==p[i].lt){
			    	p[i].se=z;
			    	p[i].sed=3;
			    	p[i].ltd=2;
				}
				else{
					p[i].se=y;
			    	p[i].sed=2;
			    	p[i].ltd=3;
				}
		    }
			else if(y==p[i].fi){
				p[i].fid=2;
			    if(x==p[i].lt){
			    	p[i].se=z;
			    	p[i].sed=3;
			    	p[i].ltd=1;
				}
				else{
					p[i].se=x;
			    	p[i].sed=1;
			    	p[i].ltd=3;
				}
			}
			else if(z==p[i].fi){
			   p[i].fid=3;
			    if(y==p[i].lt){
			    	p[i].se=x;
			    	p[i].sed=1;
			    	p[i].ltd=2;
				}
				else{
					p[i].se=y;
			    	p[i].sed=2;
			    	p[i].ltd=1;
				}
		    }
		}
		sort(p+1,p+1+n,cmp);
		int k=n/2;
		int i=1;
		for(int i=1;i<=n;i++){
		    if(cnt[p[i].fid]<k&&cnt[p[i].sed]<k){
		    	if(p[i].fi-p[i].lt<p[i+1].fi){
					if(p[i].fid==p[i+1].fid){
						ans=ans+p[i].se+p[i+1].fi;
						cnt[p[i].sed]++;
						cnt[p[i+1].fid]++;
					}
					else{
						ans=ans+p[i].fi+p[i+1].fi;
						cnt[p[i].fid]++;
						cnt[p[i+1].fid]++;
					}
				}
				else{
					ans+=p[i].fi;
					cnt[p[i].fid]++;
				}
			}
			else if(cnt[p[i].ltd]<k){
				ans+=p[i].lt;
				cnt[p[i].ltd]++;
				continue;
			}
        }
	cout<<ans<<endl;
}
return 0;
}
