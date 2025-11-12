#include<bits/stdc++.h>
using namespace std;
char st;
int sh[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	while(cin>>st)
	{
		if(st>='0'&&st<='9')
		{
			j++;
			sh[j]=st-'0';
		}
	}
	sort(sh+1,sh+j+1,cmp);
	for(int k=1;k<=j;k++)
	{
		cout<<sh[k];
	}
	return 0;
}