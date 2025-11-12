#include <bits/stdc++.h>
#define int long long
#define debug cout<<"!";
using namespace std;
constexpr int N=1e5+5;
int T,n,a[N][5],ans;
int pos[N];
int bu[5];
pair<int,int> super[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(bu,0,sizeof(bu));
		memset(pos,0,sizeof(pos));
		memset(a,0,sizeof(a));
		memset(super,0,sizeof(super));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxn=0,maxind;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxn){
					maxn=a[i][j];
					maxind=j;
				}
			}
			pos[i]=maxind;
			ans+=maxn;
			bu[maxind]++;
		}
		int tagcol=-1;
		for(int j=1;j<=3;j++){
			if(bu[j]>n/2){
				tagcol=j;
			}
		}
		if(tagcol==-1){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int max1=0,max2=0;
			int b[5];
			for(int j=1;j<=3;j++){
				b[j]=a[i][j];
			}
			sort(b+1,b+1+3);
			max1=b[3],max2=b[2];
			super[i].first=max1-max2;
			super[i].second=i;
		}
		sort(super+1,super+1+n);
		int need=bu[tagcol]-n/2;
		int cnt=0,i=0;
		while(cnt<need){
			i++;
			if(pos[super[i].second]==tagcol){
				ans-=super[i].first;
				cnt++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;	
}
