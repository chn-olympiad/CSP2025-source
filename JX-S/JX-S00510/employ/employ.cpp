#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,m,a[1000],c[1000],ans;
string s;
bool flag;
ll check(){
	ll sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]||s[i]=='0'){
			cnt++;
			continue;
		}
		sum++;
		if(sum>=m) return 1;
	}
	return 0;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		a[i]=i;
		if(s[i]=='0') flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(!flag){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	ans+=check();
	while(next_permutation(a+1,a+1+n)){
		ans+=check();
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
