#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005][4],ans,cnt[4],b[100005],cho[100005];
signed main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				ans+=a[i][1];
				cho[i]=1;
				continue;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				ans+=a[i][2];
				cho[i]=2;
				continue;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt[3]++;
				ans+=a[i][3];
				cho[i]=3;
				continue;
			}
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		int tot=0;
		if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(cho[i]==1){
					b[++tot]=a[i][1]-max(a[i][2],a[i][3]);
				}
			}
			sort(b+1,b+cnt[1]+1);
			int tim=cnt[1]-n/2;
			for(int i=1;i<=tim;i++){
				ans-=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(cho[i]==2){
					b[++tot]=a[i][2]-max(a[i][1],a[i][3]);
				}
			}
			sort(b+1,b+cnt[2]+1);
			int tim=cnt[2]-n/2;
			for(int i=1;i<=tim;i++){
				ans-=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt[3]>n/2){
			for(int i=1;i<=n;i++){
				if(cho[i]==3){
					b[++tot]=a[i][3]-max(a[i][2],a[i][1]);
				}
			}
			sort(b+1,b+cnt[3]+1);
			int tim=cnt[3]-n/2;
			for(int i=1;i<=tim;i++){
				ans-=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}


