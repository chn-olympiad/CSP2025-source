#include<bits/stdc++.h>
using namespace std;
string q;
string z[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	cin>>q;
	for(long long i=0;i<q.size();i++)
	{
		if('0'<=q[i]<='9')
		{
			z[q[i]-'0']+=q[i];
		}
	}
	for(long long i=9;i>=0;i--)
	{
	cout<<z[i];
	}
	return 0;
}
