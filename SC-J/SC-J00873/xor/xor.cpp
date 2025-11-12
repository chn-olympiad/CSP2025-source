#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=5e5+5;
vector<pair<int,int>>s;
int n,k,a[MAX];
bool check(int l,int r){
	if(l>r)return false;
	int res=0;
	for(int i=l;i<=r;i++)res^=a[i];
	return(res==k);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0&&n<=2){
		if(n==1){
			if(a[1]==k)cout<<"1\n";
			else cout<<"0\n";
		}else{
			if((a[1]^a[2])==k)cout<<"1\n";
			else cout<<"0\n";
		}
		return;
	}
	for(int l=1;l<=n;l++)for(int r=1;r<=n;r++)if(check(l,r))s.push_back({l,r});
	sort(s.begin(),s.end());
	int len=s.size(),ans=0;
	for(int i=0;i<len-1;i++){
		if(s[i].first>=0){
			if(s[i].second<s[i+1].first)ans++;
			else{
				s[i+1].first=-1;
				ans++;
			}
		}
	}
	if(s[len-1].first!=-1)ans++;
	cout<<ans<<'\n';
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}