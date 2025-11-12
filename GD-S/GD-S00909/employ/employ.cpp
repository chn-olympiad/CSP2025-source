#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
bool cmp(int a,int b){
	return a<b;
}
char s[505];
ll c[505],cnt[505];
ll alsort(ll n,ll m){
	ll ans=1,num=n;
	for(int i=n;i>(n-m);i--){
		ans*=num;
		num--;
	} 
	return ans;
}
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt[c[i]]++;
	}
	sort(c+1,c+1+n,cmp);
	ll ans=1,cnt1=0,l=0,dp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')dp++;
		if(c[i]!=c[i-1]&&i!=1)cnt1+=cnt[c[i]];
		if(c[i]==dp){
			ans*=alsort(cnt1+cnt[c[i]],i-l);
			ans%=mod;
			l=i;
			i+=cnt[c[i]]-1;
			cnt1+=cnt[c[i]];
			continue;
		}
		
	}
	ans+=alsort(cnt1,n-l);
	ans%=mod;
	cout<<ans;
	return 0;
}

