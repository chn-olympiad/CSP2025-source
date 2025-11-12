#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,cnt;
int num[505],c[505];
string s,a;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a+='1';
	for(int i=1;i<=n;i++) cin>>c[i],num[i]=i;
	if(s==a){
		cnt=1;
		for(int i=1;i<=n;i++){
			cnt=cnt*i%mod;
		}
		cout<<cnt%mod;
		return 0;
	}
	do{
		int lo=0,pa=0;
		for(int i=1;i<=n;i++){
			if(lo>=c[num[i]]) lo++;
			else{
				if(s[i-1]=='0') lo++;
				else pa++;
			}
		}
		if(pa>=m) cnt++;
	}while(next_permutation(num+1,num+n+1));
	cout<<cnt%mod;
	return 0;
}
