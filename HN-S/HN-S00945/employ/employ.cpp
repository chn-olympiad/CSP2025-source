#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],p[505],f[505][505][505],ans;
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		p[i]=i;
		do{
			int cnt=0,tot=0;
			for(int i=1;i<=n;i++){
				if(cnt>=c[p[i]]||s[i]=='0') cnt++;
				else tot++;
			}
			if(tot>=m) ans++;

		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
	return 0;
}
/*
dp but i cant solve this
baoli
*/