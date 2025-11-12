#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5e2+10;

int n,m,a[N],p[N],ans,prod[N];
string s;

bool check(){
	int kill=0,emp=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			kill++;
			continue;
		}
		if(p[a[i]]>kill)emp++;
		else kill++;
	}
	return emp>=m;
}

int expow(int b,int p){
	if(p==0)return 1;
	if(p==1)return b;
	int temp=expow(b,p/2);
	if(p%2==0)return temp*temp%MOD;
	return temp*temp%MOD*b%MOD;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(n<=18){
		for(int i=1;i<=n;i++)a[i]=i;
		do{
			if(check())ans++;
		}while(next_permutation(a+1,a+1+n));
	}else {
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
	}
	cout<<ans;
	return 0;
}
