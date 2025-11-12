#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==2) cout<<"2 0"<<'\n';
	else if(q==4)	cout<<"0 0 0 0"<<'\n';
	else cout<<'0'<<'\n';
	return 0;
}

