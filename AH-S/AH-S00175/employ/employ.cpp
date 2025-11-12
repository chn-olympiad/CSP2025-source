#include<bits/stdc++.h>
using namespace std;
//~ #define int long long
const int M = 998244353;

int n,m,a[505],s1,s0,ans;
string s;

int qp(int a,int b){
	int res=1;
	if(a==-1){
		if(b&1)return -1;
		return 1;
	}
	if(b==0)return 1;
	if(a==0||a==1||b==1)return a;
	while(b){
		if(b&1)res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(char i:s){
		if(i=='1')s1++;
		else s0++;
	}
	int tmp=0;
	for(int i=s1;i>s0;i--)ans+=qp(i,i-1)*(++tmp&1?1:-1);
	cout<<ans;
	return 0;
}
//3*23*23*137
