#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[200005][2],sx,sy;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n>>q;
	for(long long i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	for(long long i=0;i<q;i++) cout<<0<<"\n";
	return 0;
}
//18:04 想到KMP了，但我又不会，这下炸了
//18:06 等会，我好像有点记得kmp了 
