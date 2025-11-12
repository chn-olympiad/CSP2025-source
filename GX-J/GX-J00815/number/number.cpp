#include<bits/stdc++.h>
using namespace std;
long long a[10000000],cnt=0,l;
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","W",stdout);
cin>>s;
l=s.size();
for(long long i=0;i<l;i++)
{
	if('0'<=s[i]&&s[i]<='9')
	{
		a[cnt]=s[i]-'0';
		cnt++;
	}
}
sort(a,a+cnt);
for(long long i=cnt-1;i>=0;i--)
{
	cout<<a[i];
}
return 0;
}
