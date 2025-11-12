//GZ-S00318 贵州省绥阳中学  王开润 
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s;
int a[100005];
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long ans=1;
	cin>>n>>m;
	cin>>s;	
	int o=0;
	int len=s.size();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			o++;
		}
	}
		cout<<o<<endl;
	int num=0;
	for(int i=0;i<len;i++)
	if(s[i]=='1')num++;
	//cout<<num;
	if(num==len)
	{
		for(int i=1;i<=n-o;i++)
		ans=ans*i%998244353;
	}//
	cout<<ans;
	return 0;
}

