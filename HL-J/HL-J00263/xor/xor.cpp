#include<bits/stdc++.h>
using namespace std;
string str;
int n,m,s,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>x;
		if(x==m)
			s++;
	}
	cout<<s+1<<endl;
	return 0;
}
 