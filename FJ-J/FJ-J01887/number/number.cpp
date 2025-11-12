#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll i,j,x,m,num=0,length=0;
char leng;
ll a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	s=' ';
	cin>>s;
	
	for(i=0;i<=5000;i++)
	{
		if(s[i] -'0'<=9&&s[i] -'0'>=0)
		{
			num++;
			a[num]=s[i]-'0';
			
		}
	}
	sort(a+1,a+num+1);
	for(j=num;j>=1;j--)
		cout<<a[j];
		
	return 0;
}
