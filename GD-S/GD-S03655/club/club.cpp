#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int _=1; _<=t; _++){
		int n;cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		int cnt1=0,cnt2=0,ans=0;
		for(int i=1; i<=n; i++){
			if(a[i]>b[i]&&cnt1<=n/2){
				ans+=a[i];
				cnt1++;
			}
			else if(cnt2<=n/2){
				ans+=b[i];
				cnt2++;
			}
		}
		cout<<ans<<'\n';
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
} 
