#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
struct ppp{int a1,a2,a3;}a[100100];
bool cmp(ppp x,ppp y){return x.a1>y.a1;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a1>>a[i].a2>>a[i].a3;
		int c1=0,c2=0,ans=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2&&c1<n/2)ans+=a[i].a1,c1++;
			else if(c>=n/2)ans+=a[i].a2,c2++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
