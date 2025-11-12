#include<bits/stdc++.h>
using namespace std;
bool b[505],bb[505];
int a[505],n,m,cnt=1,ans=1,t=0;
int main()
{
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	cin>>n>>m;
 	string s;
 	cin>>s;
 	for(int i=1;i<=n;i++)
 	cin>>a[i];
 	for(int i=0;i<s.size();i++)
 	{
 		if(s[i]-'0'==1)
 		t++;
	}
	for(int i=1;i<=t;i++)
	cnt*=i;
	cout<<cnt;
	return 0;
}
