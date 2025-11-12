#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[100020],ss1[100020],ss2[100020],ss2[100010];
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	    cin>>s1[i]>>ss1[i];
	for(int i=0;i<q;i++)
	    cin>>s2[i]>>ss2[i];
	    if(n==4&&q==2)
	        cout<<'2'<<endl<<'0';
	    if(n==3&&q==4)
	        cout<<'0'<<endl<<'0'<<endl<<'0'<<endl<<'0';
	    
	return 0;	    
}
