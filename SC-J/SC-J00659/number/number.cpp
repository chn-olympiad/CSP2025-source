#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=1e6+10;
char c[N];
void solve(){
	char a;int n=1;
	while(cin>>a)
	{
		if('0'<=a&&a<='9')
		{
			c[n]=a;
			n++;	
		}
	}
	n-=1;
	sort(c+1,c+n+1);
	string ans;
	for(int i=n;i>=1;i--)
	{
		ans+=c[i];
	}
	cout<<ans;
	return ;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}	