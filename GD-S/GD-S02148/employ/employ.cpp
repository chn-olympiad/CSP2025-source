#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=998244353;
int n,m;
string s;
int a[N];
int c[N];
int idd[N];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		idd[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	do{
		int cnt=0;
		int res=0;
		for(int i=1;i<=n;i++){
			if(res>=m) break;
			if(c[idd[i]]>cnt && a[i]) res++;
			else cnt++;
		}
		if(res>=m) ans=(ans+1)%mod;
	}while(next_permutation(idd+1,idd+n+1));
	cout<<ans;
	return 0;
}
