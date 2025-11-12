#include<iostream>
#include<algorithm>
using namespace std;
int t;
int n;
int a[(int)1e5+5][5];
int maxid[(int)1e5+5],secid[(int)1e5+5];
int cnt[5];
int d[(int)1e5+5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			maxid[i]=secid[i]=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>a[i][maxid[i]]) secid[i]=maxid[i],maxid[i]=j;
				else if(a[i][j]>a[i][secid[i]]) secid[i]=j;
			}
			cnt[maxid[i]]++;
			ans+=a[i][maxid[i]];
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				for(int j=1;j<=n;j++){
					if(maxid[j]==i) d[j]=a[j][maxid[j]]-a[j][secid[j]];
					else d[j]=2e9;
				}
				sort(d+1,d+n+1);
				for(int j=1;j<=cnt[i]-n/2;j++) ans-=d[j];
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

