#include <bits/stdc++.h>
using namespace std;
const int N = 200010,M = 5000010;
char s1[M],s2[M];
struct Node
{
	int len,mid1,mid2;
}a[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		int mid1=0,mid2=0;
		for (int i=1;i<=len;i++)
		{
			if (s1[i]=='b') mid1=i;
			if (s2[i]=='b') mid2=i;
			if (mid1&&mid2) break;
		}
		a[i]={len,mid1,mid2};
	}
	while (q--)
	{
		int ans=0;
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		int mid1=0,mid2=0;
		for (int i=1;i<=len;i++)
		{
			if (s1[i]=='b') mid1=i;
			if (s2[i]=='b') mid2=i;
			if (mid1&&mid2) break;
		}
		for (int i=1;i<=n;i++)
		{
			Node e=a[i];
			int _len=e.len,_mid1=e.mid1,_mid2=e.mid2;
			if (len<_len) continue;
			if (mid1>=_mid1&&(len-mid2)>=(_len-_mid2)&&(mid1-mid2)==(_mid1-_mid2)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
