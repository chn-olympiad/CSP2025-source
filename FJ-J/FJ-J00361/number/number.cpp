#include <bits/stdc++.h>
using namespace std;

long long a[1000050];

int main()
{
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	string s;
 	cin>>s;
 	long long num=0;
 	for(long long i=0;i<s.size();i++)
 	{
 		if('0'<=s[i]&&s[i]<='9')
 		{
 			num++;
 			a[num]=(s[i]-48);
 		}
 	}
 	sort(a+1,a+num+1);
 	for(long long i=num;i>=1;i--)cout<<a[i];
   	return 0;
}

