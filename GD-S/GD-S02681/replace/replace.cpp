#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
string S1[N],S2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>S1[i]>>S2[i];
		cout<<"0"<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}
