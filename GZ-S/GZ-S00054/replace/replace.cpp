//GZ-S00054 刘宸浩 兴义市第八中学 
#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=200005;
string s[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>s[i][j];
		}
	}
	return 0;
}
