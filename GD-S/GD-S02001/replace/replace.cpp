#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int n,q;
string s[200005][3];
map<string,string>mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
			continue;
		}
		bool f=1;
		for(int i=0;i<a.size();i++)
		{
			if((a[i]=='a'||a[i]=='b')&&(b[i]=='a'||b[i]=='b')){
			}else {
				f=1;
			}
		}
		f=1;
		if(f){
			cout<<0<<endl;
			continue;
		}
//		int m=a.size();
//		a=" "+a;
//		for(int i=1;i<=m;i++)
//		{
//			
//		}
	}
	return 0;
}
