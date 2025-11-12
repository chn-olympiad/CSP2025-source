#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[510],p[510],ans;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	do{
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i-1]=='0')cnt++;
			else cnt2++;
		}
		if(cnt2>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
}
/*
500500500500500500
*/
