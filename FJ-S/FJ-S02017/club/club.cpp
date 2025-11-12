#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN],c[MAXN],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(b[1]==0&&c[1]==0){
			sort(a+1,a+1+n);
			int ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}else if(c[1]==0){
			int tot=0,d[MAXN];
			for(int i=1;i<=n;i++){
				tot+=a[i];
				d[i]=a[i]-b[i];
			}
			sort(d+1,d+1+n);
			for(int i=1;i<=n/2;i++){
				tot-=d[i];
			}
			cout<<tot<<"\n";
		}
	}
	return 0;
}
