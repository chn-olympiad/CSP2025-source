#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[500001],p[500001],an;
char s[500001];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	do{
		int su=0,no=0;
		for(int i=1;i<=n;i++){
			if(no>=c[p[i]])no++;
			else{
				if(s[i-1]=='0')no++;
				else su++;
			}
		}
		if(su>=m)an=(an+1)%998244353;
	}while(next_permutation(p+1,p+n+1));
	cout<<an;
	return 0;
}