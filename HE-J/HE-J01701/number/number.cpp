#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	char b[1e6+2];
	int d=0;
	for(int i=0;i<=1e6;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		if(a[i]>='0'&&a[i]<='9')
		{
			b[d]=a[i];
			d++;
		}else{
			continue;
		}
	}
	sort(b,b+d+1,cmp);
	for(int i=0;i<d;i++)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
