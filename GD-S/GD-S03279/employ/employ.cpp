#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505;
int n,m,c[N],p[N],ans;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int sum=0,rf=0;
		for(int i=1;i<=n;i++){
			if(rf>=c[p[i]]||s[i]=='0'){
				rf++;
				continue;
			}
			sum++;
		} 
		if(sum>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}

