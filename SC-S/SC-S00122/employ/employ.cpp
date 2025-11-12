#include<bits/stdc++.h>
#define N 105
#define mod 998244353
using namespace std;
int p[N],a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[i]=i;
	}
	int ans=0;
	do{
		int nx=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(nx>=p[a[i]])nx++;
			else if(s[i-1]=='0')nx++;
			else{
				nx=0;
				cnt++;
			}
		} 
		if(cnt>=m)ans=(ans+1)%mod;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}