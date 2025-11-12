#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=998244353;
ll n,m,c[600],p[20];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(m==n){
		for(int i=0;i<s.size();++i){
			if(s[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;++i) p[i]=i;
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i){
//				cout<<i<<' '<<cnt<<' '<<s[i]<<' '<<p[i]<<' '<<c[p[i]]<<endl;
				if(cnt>=c[p[i]]||s[i-1]=='0') ++cnt;
			}
//			for(int i=1;i<=n;++i) cout<<p[i]<<' ';
//			cout<<endl;
//			cout<<cnt<<endl;
			if(n-cnt>=m) ++ans;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<endl;
	}
	return 0;
}

