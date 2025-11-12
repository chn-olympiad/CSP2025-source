#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,cnt[505],m,c[505],ans=1,t,a[505],b[505];
string s;
bool f=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt[c[i]]++;
	}
	sort(c+1,c+n+1);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			a[++t]=i;
			f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			(ans*=i)%=MOD;
		}
		cout<<ans;
		return 0;
	}
	ll p=0;
	for(int i=1;i<=t;i++){
		b[i]=a[i]-a[i-1];
		b[i]+=b[i-1];
		while(cnt[p]==0){
			p++;
		}
		if(i>p){
			m+=cnt[p++];
			i--;
			continue;
		}
		if(b[i]<cnt[p]){
			continue;
		}
		for(int i=1;i<=cnt[p];i++){
			(ans*=i)%=MOD;
		}
		b[i]-=cnt[p];
	}
	if(m>n){
		cout<<0;
	}
	else{
		cout<<ans;
	}
	return 0;
}
