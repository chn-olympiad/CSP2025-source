#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
const int N=200005;
const int LEN=2000005;

int n,q;
int len[N];
char s1[LEN],s2[LEN];
ULL t1[LEN],t2[LEN];
int l;
ULL a1[LEN],a2[LEN];
ULL base[LEN];
LL ans;
ULL get_hash1(int l,int r)
{
	if (l>r) return 0;
	return t1[r]-t1[l-1]*base[r-l+1];
}
ULL get_hash2(int l,int r)
{
	if (l>r) return 0;
	return t2[r]-t2[l-1]*base[r-l+1];
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	base[0]=1;
	for (int i=1;i<=LEN-5;i++)
	{
		base[i]=base[i-1]*29;
	}
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		len[i]=0;
		while (s1[1+len[i]]!='\0') len[i]++;
		for (int j=1;j<=len[i];j++)
		{
			a1[i]=a1[i]*29+(s1[j]-'a'+1);
			a2[i]=a2[i]*29+(s2[j]-'a'+1);
		}
		// cout<<a1[i]<<","<<a2[i]<<endl;
	}
	while (q--)
	{
		scanf("%s%s",s1+1,s2+1);
		ans=0;
		l=0;
		while (s1[1+l]!='\0') l++;
		for (int i=1;i<=l;i++)
		{
			t1[i]=t1[i-1]*29+(s1[i]-'a'+1);
			t2[i]=t2[i-1]*29+(s2[i]-'a'+1);
			// printf("%d:%lld,%lld\n",i,t1[i],t2[i]);
		}
		// printf("l:%d\n",l);
		for (int i=1;i<=l;i++)
		{
			if (t1[i-1]!=t2[i-1]) break;
			for (int j=1;j<=n;j++)
			{
				if (i+len[j]-1>n)continue;
				if(get_hash1(i+len[j],l)==get_hash2(i+len[j],l)&&get_hash1(i,i+len[j]-1)==a1[j]&&get_hash2(i,i+len[j]-1)==a2[j])
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}