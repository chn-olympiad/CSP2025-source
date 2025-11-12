#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans;string s;
struct p{
	long long i,x;
	bool operator<(p b){return i<b.i;}
}c[505];
void chk(){
	long long cnt=0;
	for(long long i=0;i<n;i++){
		if(s[i]=='0'||c[i].x<=cnt)cnt++;
	}
	ans=(ans+(m<=(n-cnt)))%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=0;i<n;i++)c[i].i=i,cin>>c[i].x;
	sort(c,c+n);
	do{
		chk();
	}while(next_permutation(c,c+n));
	cout<<ans;
	return 0;
}
