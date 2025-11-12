//GZ-S00054 刘宸浩 兴义市第八中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=505;
string s;
int c[N];
int num,ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||num>=c[i]) 
		{
			c[i]=-1;
			num++;
		}else{
			ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
