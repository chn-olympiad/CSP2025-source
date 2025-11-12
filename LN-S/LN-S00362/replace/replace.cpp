#include <bits/stdc++.h>
using namespace std;
int main( )
{
	int p,q,s=0;
	char a[10000],b[10000];
	cin>>p>>q;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	//freopen(replace.in,"r",stdin)
	//freopen(replace.out,"w",stdout)
	for(int j=1;j<=q;j++)
		{
			cin>>b[j];
			if(a[j]==b[j])
			{
				s++;
			}
		}
		cout<<s<<endl;
		for(int j=1;j<=q-1;j++)
		{
			cout<<"0"<<endl;
		}
	return 0;
}
