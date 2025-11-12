#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+5;
struct db{
	string s1,s2;
	int d1,d2,len;
}s[N];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		cin>>s[i].s1>>s[i].s2;
		int len=s[i].s1.size();
		int l=0,r=len-1;
		while(l<len&&s[i].s1[l]==s[i].s2[l]) l++;
		if(l>=len)
		{
			i--;
			n--;
			s[i].s1.clear();
			s[i].s2.clear();
			continue;
		}
		while(r>=0&&s[i].s1[r]==s[i].s2[r]) r--;
		s[i].d1=l;
		s[i].d2=r;
		s[i].len=len;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		int l=0,r=len1-1;
		while(l<len1&&t1[l]==t2[l]) l++;
		while(r>=0&&t1[r]==t2[r]) r--;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(r-l!=s[i].d2-s[i].d1||l<s[i].d1||len1-r<s[i].len-s[i].d2) continue;
			bool flag=1;
			for(int j=0;j<=r-l;++j)
				if(t1[l+j]!=s[i].s1[s[i].d1+j]||t2[l+j]!=s[i].s2[s[i].d1+j])
				{
					flag=0;
					break;
				}
			if(!flag) continue;
			for(int j=0;s[i].d1-j-1>=0;++j)
				if(t1[l-j-1]!=s[i].s1[s[i].d1-j-1]||t2[l-j-1]!=s[i].s2[s[i].d1-j-1])
				{
					flag=0;
					break;
				}
			if(!flag) continue;
			for(int j=0;s[i].d2+j+1<s[i].len;++j)
				if(t1[r+j+1]!=s[i].s1[s[i].d2+j+1]||t2[r+j+1]!=s[i].s2[s[i].d2+j+1])
				{
					flag=0;
					break;
				}
			if(!flag) continue;
			ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
