#include <bits/stdc++.h>
using namespace std;
const int maxv=99999999;
char str1[maxv],str2[maxv];
bool cmp (int a,int b) 
{
    return a > b ; 
}
int main()
{
	
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	
	cin >> str1;
	int cnt=strlen(str1);
	for(int i=0;i<=cnt;i++)
	{
		if((int)str1[i]>=48 and (int)str1[i]<=57)
		{
			str2[i]=str1[i];
		}  
	}
    sort(str2,str2+cnt,cmp);
	for(int i=0;i<=cnt;i++)
	{
		cout << str2[i] ;
	}
	return 0;
}
