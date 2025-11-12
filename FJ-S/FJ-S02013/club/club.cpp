#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100010][3],ans,s[3],b[100010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;ans=s[0]=s[1]=s[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])s[0]++,ans+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])s[1]++,ans+=a[i][1];
			else s[2]++,ans+=a[i][2];
		}
		if(s[0]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])b[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				else b[i]=1e9;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=s[0]-n/2;i++)ans-=b[i];
		}
		if(s[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])b[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				else b[i]=1e9;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=s[1]-n/2;i++)ans-=b[i];
		}
		if(s[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])b[i]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				else b[i]=1e9;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=s[2]-n/2;i++)ans-=b[i];
		}
		cout<<ans<<"\n";
	}
}
/*
123412341234123
*/
