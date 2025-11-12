#include <bits/stdc++.h>
using namespace std;
char a[1000005],c[10000005];
int cnt=1;
bool cmp(char a,char b){
	return a<b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for (int i=0;i<1000005;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[cnt]=c[i];
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
