#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,mod=998244353;
int n,m,ans,fact[N];
string s;
int c[N],buk[N];


int calc(){
	int cnt=0,reg=0;
	for(int i=1;i<=n;i++){
		if(c[i]>reg&&(s[i-1]=='1'))cnt++;
		else reg++;
	}
	return cnt>=m;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i],buk[c[i]]++;
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
	sort(c+1,c+n+1);
	do{
		ans+=calc();
	}while(next_permutation(c+1,c+n+1));
	for(int i=1;i<=n;i++){
		ans=ans*fact[buk[i]]%mod;
	}
	cout<<ans;
	return 0;
}
