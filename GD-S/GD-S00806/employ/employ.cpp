#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=504;
const int mod=998244353;
char s[N];
int c[N];
int a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)a[i]=i;
	int ans=0;
	do{
		int cnt=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
			}
			else if(cnt>=c[a[i]])cnt++;
			else sum++;
			if(sum==m){
				ans++;
				ans=ans%mod;
				break;
			}
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<"\n";
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

