#include<bits/stdc++.h>
using namespace std;
string s;
string ss;
long long a[10000005];
long long bmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long ws=0;
	cin>>s;
	long long len=s.size(),ans=0;
	for(long long i=0;i<=len-1;i++)
	 {
		 if(s[i]>='0'&&s[i]<='9')
			{ws++;a[ws]=s[i]-'0';}
		}
	sort(a+1,a+1+ws,bmp);
	for(long long i=1;i<=ws;i++) 
		 ans=a[i]*10+ans*10;
	 ans=ans/10;
	 cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
