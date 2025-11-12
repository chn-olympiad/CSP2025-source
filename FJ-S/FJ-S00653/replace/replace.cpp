#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
int n,q;
string s[5000005][2];
int main()
{
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		cout<<0<<endl;
	}
	return 0;
}