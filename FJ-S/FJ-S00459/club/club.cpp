#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
struct jgt{
	int la,lb,lc;
	int c;
	int k;
	int mx;
};
int n,ans,ka,kb,kc;
jgt a[N];
bool cmp(jgt x,jgt y){
	if(x.k!=y.k) return x.k<y.k;
	else return x.c<y.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		ka=0,kb=0,kc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].la>>a[i].lb>>a[i].lc;
			if(a[i].la>=a[i].lb&&a[i].la>=a[i].lc){
				ka++;
				a[i].k=1;
				ans+=a[i].la;
				if(a[i].lb>a[i].lc){
					a[i].c=a[i].la-a[i].lb;
				}
				else{
					a[i].c=a[i].la-a[i].lc;
				}
			}
			
			
			else if(a[i].lb>=a[i].la&&a[i].lb>=a[i].lc){
				kb++;
				a[i].k=2;
				ans+=a[i].lb;
				if(a[i].la>a[i].lc){
					a[i].c=a[i].lb-a[i].la;
				}
				else{
					a[i].c=a[i].lb-a[i].lc;
				}
			}
			
			
			else if(a[i].lc>=a[i].la&&a[i].lc>=a[i].lb){
				kc++;
				a[i].k=3;
				ans+=a[i].lc;
				if(a[i].la>a[i].lb){
					a[i].c=a[i].lc-a[i].la;
				}
				else{
					a[i].c=a[i].lc-a[i].lb;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		if(ka>n/2){
			for(int i=1;i<=ka-n/2;i++){
				ans-=a[i].c;
			}
		}
		else if(kb>n/2){
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid].k<2) l=mid+1;
				else r=mid-1;
			}
			for(int i=l;i<l+kb-n/2;i++){
				ans-=a[i].c;
			}
		}
		else if(kc>n/2){
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid].k<=2) l=mid+1;
				else r=mid-1;
			}
			for(int i=l;i<l+kc-n/2;i++){
				ans-=a[i].c;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
