#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=1000,Mod=998244353;
int n,m,a[N],ans;
string s;
bool check(string s){
	int w=s.size();
	for(int i=0;i<w;i++){
		if(s[i]=='0')return 0;
	}
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(check(s)){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=Mod;
		}
		cout<<ans;
	}	
	else{
		cout<<0;
	}	
	return 0;
}


