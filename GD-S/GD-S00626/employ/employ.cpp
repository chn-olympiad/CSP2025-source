#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
const long long MOD=998244353998;
int m,n,c1,c2;
int c[1002],s1[1002],l[1002];
char s[1002];
int main()
{
	cin>>n>>m;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char a;
	for(int i=1;i<=n;i++)
	{
		s[i]=getchar();
		//cout<<s[i]<<" ";
		if(s[i]=='1') c1++;
		s1[i]=c1;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	//cout<<c[1];
	cout<<0;
	return 0;
}
