#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::sort;

const int N=1e5+5;

int t,n,a[N],b[N],c[N],w[N],ans,ans1;
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=ans1=0;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		
		
		for(int i=1;i<=n;i++) w[i]=c[i]- (i>n/2? a[i]:b[i]),ans1+=i>n/2? a[i]:b[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		
		for(int i=1;i<=n;i++) w[i]=c[i]- (i>n/2? b[i]:a[i]),ans1+=i>n/2? b[i]:a[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		
		for(int i=1;i<=n;i++) w[i]=b[i]- (i>n/2? a[i]:c[i]),ans1+=i>n/2? a[i]:c[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		
		for(int i=1;i<=n;i++) w[i]=b[i]- (i>n/2? c[i]:a[i]),ans1+=i>n/2? c[i]:a[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		
		for(int i=1;i<=n;i++) w[i]=a[i]- (i>n/2? b[i]:c[i]),ans1+=i>n/2? b[i]:c[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		
		for(int i=1;i<=n;i++) w[i]=a[i]- (i>n/2? c[i]:b[i]),ans1+=i>n/2? c[i]:b[i];
		sort(w+1,w+n+1);
		for(int i=n;i>n/2&&w[i]>0;i--) ans1+=w[i];
		ans=max(ans,ans1),ans1=0;
		cout<<ans<<'\n';
	}
	return 0;
}
