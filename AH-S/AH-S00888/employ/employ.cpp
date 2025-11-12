#include <iostream>
#include <algorithm>
using namespace std;
const int N=500,MOD=998244353;
int n,m,c[N+5],cnt,p[N+5];
char s[N+5];
long long ans=1;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;++i)
		if(s[i]=='1')flag=1;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		cnt+=!c[i];
		ans=ans*i%MOD;
	}
	if(!flag){
		if(n>=m+cnt)cout<<ans<<'\n';
		else cout<<"0\n";
		return 0;
	}else{
		for(int i=1;i<=n;++i)p[i]=i;
		ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(s[i]=='0'||cnt>=c[i])++cnt;
			if(n-cnt>=m)++ans;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
	}
	return 0;
}

