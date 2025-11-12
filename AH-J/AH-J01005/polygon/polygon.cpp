#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int s,a[100000000];
	cin>>s;
	for(int i=1;i<=s;i++)
		cin>>a[i];
	cout<<int(s*(s-1)/2);
	return 0;
}
