#include <bits/stdc++.h>
using namespace std;
#define N 510
int n,m,emp=0,c[N],np=0;
int a[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int wi=1;
	char ch;
	ch=getchar();
	while(wi<=n)
	{
		if(ch=='0'||ch=='1')
		{
			a[wi]=ch-'0';
			if(a[wi]==1)emp++;
			wi++;
		}
		ch=getchar();
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]==0)np++;
	}
	if(n-np<m)cout<<0;
	if(emp<m)cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

