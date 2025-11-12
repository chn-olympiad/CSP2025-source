#include<iostream>
#include<cstring> 
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;
const int Max=2e5+10;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0',c=getchar();}
	return sum*f;
}
struct node
{
	string s1,s2;
	int l,cha;
}a[Max];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long ans=0;
	int n,q;
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		a[i].l=a[i].s1.size(); 
		int jr1=0,jr2=0;
		for(int j=0;j<a[i].l;j++)
		{
			if(a[i].s1[j]=='b') jr1=j;
			if(a[i].s2[j]=='b') jr2=j; 
		}
		a[i].cha=jr1-jr2;
	}
	if(q==1)
	{
		long long ans=0;
		for(int i=1;i<=q;i++)
		{
			int l,jr1,jr2,cha;
			string s1,s2;
			cin>>s1>>s2;
			l=s1.size();
			for(int j=0;j<a[i].l;j++)
			{
				if(s1[j]=='b') jr1=j;
				if(s2[j]=='b') jr2=j; 
			}
			cha=jr1-jr2;
			for(int j=1;j<=n;j++) if(s1.find(a[j].s1)==true||s1==a[j].s1) if(a[j].cha==jr1-jr2) ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
