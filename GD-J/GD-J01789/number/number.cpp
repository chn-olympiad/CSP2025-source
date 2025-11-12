#include<bits/stdc++.h>
using namespace std;
#define N 1000010

char a[N],b[N];

bool cmp(char c1,char c2)
{
	return c1>c2;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
//	freopen("number4.in","r",stdin);
//	freopen("hi.txt","w",stdout);
	
	cin>>a+1;
	int n=strlen(a+1);
	int len=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[++len]=a[i];
		}
	}
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=len;i++)cout<<b[i];cout<<'\n';
	
	
	return 0;
}
