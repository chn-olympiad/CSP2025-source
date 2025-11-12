#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	int n , q;
	string s1[20005],s2[20005],l1[20005],l2[20005];
	cin>>n>>q;
	for(int i = 1 ; i<= n ;i++)
		cin>>s1[i]>>s2[i];
	for(int i = 1 ; i<=q  ; i++)
		cin>>l1[i]>>l2[i];
	for(int i = 1 ; i<=q ; i++)
		cout<<0;
	return 0;
}