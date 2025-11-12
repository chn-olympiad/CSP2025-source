#include<bits/stdc++.h>
using namespace std;
int n,q,a[200010][2],b[200010],c[200010];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int k;
	for (int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		k=0;
		while (s1[k++]=='a') a[i][0]++;
		b[i]=s1.size()-a[i][0]-1;
		k=0;
		while (s2[k++]=='a') a[i][1]++;
		c[i]=a[i][0]-a[i][1];
	}
	while (q--)
	{
		cin>>s1>>s2;
		int k=0,ans=0,aa=0,bb=0,cc=0,dd=0;
		while (s1[k++]=='a') aa++;
		bb=s1.size()-aa-1;
		k=0;
		while (s2[k++]=='a') dd++;
		cc=aa-dd;
		for (int j=1;j<=n;j++)
		{
			if (a[j][0]<=aa&&cc==c[j]&&b[j]<=bb)
			ans++;
		}
		printf("%d\n",ans);
	}
	
}
