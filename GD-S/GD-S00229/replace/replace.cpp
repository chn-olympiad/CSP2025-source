#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int N=1e7+5;
//long long pre[N],mod1=998244353,mod2=100007,mod3=422721197;
string ch;
map<string,int>p;
//struct ooo
//{
//	int len;
//	long long val;
//}a[N];
int n,m,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int j=1;j<=n;j++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int st=0,ed=0;
		int u=s1.size();
		for(int i=0;i<u;i++)
		{
			if(s1[i]!=s2[i])
			{
				st=i+1;
				break;
			}
		}
		for(int i=u-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				ed=i+1;
				break;
			}
		}
//		a[j].len=ed-st+1;
		long long s=0;
		if(st)
		{
			string x;
			for(int i=st-1;i<=ed-1;i++)
			{
				x+=s1[i];
//				a[j].val=a[j].val*27+(s1[i]-'a'+1);//not strong
//				a[j].val%=mod1;
			}
			for(int i=st-1;i<=ed-1;i++)
			{
				x+=s2[i];
//				a[j].val=a[j].val*27+(s2[i]-'a'+1);//not strong
//				a[j].val%=mod1;
			}
//			cout<<x<<endl;
			p[x]++;
		}
//		cout<<st<<"aa "<<ed<<" "<<a[j].val<<endl;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		bool fl=0;
		int st=0,ed=0;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!=s2[i])
			{
				st=i+1;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				ed=i+1;
				break;
			}
		}
		string x;
		for(int i=st-1;i<=ed-1;i++)
		{
			x+=s1[i];
//			sum=sum*27+(s1[i]-'a'+1);
//			sum%=mod1;
		}
		for(int i=st-1;i<=ed-1;i++)
		{
			x+=s2[i];
//			sum=sum*27+(s2[i]-'a'+1);
//			sum%=mod1;
		}
//		if(p[sum]==360)
//		{
//			cout<<s1<<"ÖÜ "<<endl<<s2<<" ÔÎ"<<sum<<endl;
//			for(int i=st-1;i<=ed-1;i++)
//			{
//				cout<<s1[i];
//			}
//			cout<<endl;
//			for(int i=st-1;i<=ed-1;i++)
//			{
//				cout<<s2[i];
//			}
//			cout<<endl;
//		}
//		cout<<"aaa";
		cout<<p[x]<<endl;
	
	}
	return 0;
}
