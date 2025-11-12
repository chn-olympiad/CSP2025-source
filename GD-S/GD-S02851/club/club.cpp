#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,a,b,c,cha[N],maxn[N],cnt[4],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i = 1;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max({a,b,c});
			if(a>b&&a>c){
				maxn[i]=1;
				cha[i]=a-max(b,c);
			}
			else if(b>a&&b>c){
				maxn[i]=2;
				cha[i]=b-max(a,c);
			}
			else if(c>a&&c>b){
				maxn[i]=3;
				cha[i]=c-max(a,b);
			}
			else maxn[i]=0;
			cnt[maxn[i]]++;
		}
		//cout<<ans<<'\n';
		for(int i = 1;i<=3;i++){
			if(cnt[i]>n/2){
				for(int j = 1;j<=n;j++){
					if(maxn[j]==i){
						q.push(cha[j]);
					}
				}
				for(int k =cnt[i];k>n/2;k--){
					//cout<<q.top()<<' '<<cnt[i]<<' '<<n/2<<' '<<k<<'\n';
					ans-=q.top();
					q.pop();
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


