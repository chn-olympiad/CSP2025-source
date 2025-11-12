#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n;
pair<pair<int,int>,pair<int,int> > a[N];
int cnt[4];
bool cmp(pair<pair<int,int>,pair<int,int> > x,pair<pair<int,int>,pair<int,int> > y){
	if(x.first.first-x.second.first==y.first.first-y.second.first){
		return x.first.first>y.first.first;
	}
	return x.first.first-x.second.first>y.first.first-y.second.first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		int L=n/2,ans=0;
		bool flag=1;;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			if(z!=0){
				flag=0;
			}
			if(x<=y&&x<=z){
				x=0;
			}
			else if(y<=x&&y<=z){
				y=0;
			}
			else{
				z=0;
			}
			if(x>=y&&x>=z){
				a[i].first=make_pair(x,1);
				if(y<=x&&y>=z){
					a[i].second=make_pair(y,2);
				}
				else if(z<=x&&z>=y){
					a[i].second=make_pair(z,3);
				}
			}
			if(y>=x&&y>=z){
				a[i].first=make_pair(y,2);
				if(x<=y&&x>=z){
					a[i].second=make_pair(x,1);
				}
				else if(z<=y&&z>=x){
					a[i].second=make_pair(z,3);
				}
			}
			if(z>=x&&z>=y){
				a[i].first=make_pair(z,3);
				if(y>=x&&y<=z){
					a[i].second=make_pair(y,2);
				}
				else if(x>=y&&x<=z){
					a[i].second=make_pair(x,1);
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].first.second]<L){
				cnt[a[i].first.second]++;
				ans+=a[i].first.first;
				continue;
			}
			if(cnt[a[i].second.second]<L){
				cnt[a[i].second.second]++;
				ans+=a[i].second.first;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
