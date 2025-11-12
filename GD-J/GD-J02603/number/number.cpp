#include<bits/stdc++.h>
using namespace std;
char a;
long long n[1000001],j,m[1000001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)
	{
		if('0'<=a and a<='9')
		{
			n[j]=int(a)-48;
			j++;
		}
	}
	sort(n,n+j,cmp);
	for(int i=0;i<j;i++)
	{
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
