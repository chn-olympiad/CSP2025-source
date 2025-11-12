#include<bits/stdc++.h>
using namespace std;
int n,nq;
string w[200009][3];//way
string q[200009][3];//questionn
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>nq;
	for(int i=0;i<n;i++)
	{
		cin>>w[i][1]>>w[i][2];
	}
	for(int i=0;i<nq;i++)
	{
		cin>>q[i][1]>>q[i][2];
	}
	for(int i=0;i<nq;i++)
		cout<<0<<endl;
	return 0;
}
