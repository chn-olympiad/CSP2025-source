#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T;
int n;
int a[N],b[N],c[N];
int ans;
int cnt1,cnt2,cnt3;
int maxn;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=cnt1=cnt2=cnt3=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnt1++;
				ans+=a[i];
				q.push(make_pair(min(a[i]-b[i],a[i]-c[i]),1));
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				cnt2++;
				ans+=b[i];
				q.push(make_pair(min(b[i]-a[i],b[i]-c[i]),2));
			}else{
				cnt3++;
				ans+=c[i];
				q.push(make_pair(min(c[i]-a[i],c[i]-b[i]),3));
			}
		}
		maxn=n/2;
		if(cnt1<=maxn&&cnt2<=maxn&&cnt3<=maxn){
			cout<<ans<<"\n";
		}else{
			while(cnt1>maxn){
				if(q.top().second==1){
					ans-=q.top().first;
					cnt1--;
				}
				q.pop();
			}
			while(cnt2>maxn){
				if(q.top().second==2){
					ans-=q.top().first;
					cnt2--;
				}
				q.pop();
			}
			while(cnt3>maxn){
				if(q.top().second==3){
					ans-=q.top().first;
					cnt3--;
				}
				q.pop();
			}
			cout<<ans<<"\n";
		}
		
	}
	return 0;
}
