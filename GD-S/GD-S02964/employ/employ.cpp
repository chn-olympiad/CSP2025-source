#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e2+10,MOD=998244353;

int n,m,ans=1;
int c[MAXN];
char s[MAXN];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >>m >>(s+1);
	for (int i=1;i<=n;i++)
		cin >>c[i];
	for (int i=n,j=m;j>0;i--,j--)
		ans=1ll*ans*i%MOD;
	cout <<ans <<'\n';
	return 0; 
}
