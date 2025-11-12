#include<bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(),x.end()
using namespace std;
constexpr int N=501,p=998244353;
string s;
int n,m,c[N],pl[N],failed,ans,isall1=1;
signed main(){
	freopen("employ.in","r",stdin),
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>s;
	s=" "+s;
	for(auto&ch:s){
		ch^=48;
		if(!ch)
			isall1=0;
	}
	if(isall1){
		int res=1;
		for(int i=1;i<=n;i++)
			(res*=i)%=p;
		cout<<res;
		return 0;
	}
	else if(m==n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		pl[i]=i;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	do{
		failed=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0||failed>=c[pl[i]])
				failed++;
		}
		if(n-failed>=m)
			ans++;
	}while(next_permutation(pl+1,pl+n+1));
	cout<<ans%p;
	return 0;
}
