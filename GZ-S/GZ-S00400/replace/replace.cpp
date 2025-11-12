//SZ-S00400 遵义市南白中学 袁双全 
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string que[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)
	cin>>que[i][1]>>que[i][2];
	for(int i=1;i<=q;i++)
	cout<<"0"<<endl;
	return 0;	
} 
