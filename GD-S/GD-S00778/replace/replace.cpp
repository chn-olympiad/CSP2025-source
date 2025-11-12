#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long m,n;
string s1,s2;
string qus[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	while(n--)
	{
		cin>>s1>>s2;
		for(int i=1;i<=n;i++)
		{
			cin>>qus[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(qus[i].size()<2)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<m<<endl;
		}
	}
	cout<<0;
	return 0;
}

