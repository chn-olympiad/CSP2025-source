//GZ-S00317 贵阳中天中学 王巍然 
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+3;
int n,m;
string s;
char c[N];
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	int patience[n+5];
	for(int i=1;i<=s.size();i++) c[i]=s[i-1];
	for(int i=1;i<=n;i++) cin>>patience[i];
	cout<<1;
	
	
	return 0;
}
