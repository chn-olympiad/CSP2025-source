#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int cnt,a[10];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]>=48 && s[i]<=57)
		{
			a[s[i]-48]++;
		}	
	}
	sort(a,a+cnt,cmp);
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
		
	}
	return 0;
}
