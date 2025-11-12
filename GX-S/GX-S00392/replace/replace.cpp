#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<vector>
using namespace std;

int n,q;
struct nn
{
  string ch1,ch2;
  int len;
}a[200001];
bool gz(nn x,nn y)
{
  return x.ch1<y.ch1;
}
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i].ch1>>a[i].ch2;
	  a[i].len=a[i].ch1.size();
	}
	sort(a+1,a+n+1,gz);
	while(q--)
	{
	  cin>>s1>>s2;
	  if(s1.size()!=s2.size())
	  {
		printf("%d\n",0);
		continue;
	  }
	  int sum=0;
	  int we=s1.size();
	  for(int i=1;i<=n;i++)
	  {
		if(a[i].len>we)
		  break;
		for(int j=0;j<=we-a[i].len;j++)
		  if(s1.substr(j,a[i].len)==a[i].ch1)
		  {
			string c=s1.substr(0,j)+a[i].ch2+s1.substr(j+a[i].len,we-a[i].len-j);
			if(c==s2)
			  sum++;
		  }
	  }
	  printf("%d\n",sum);
	}
	return 0;
}

