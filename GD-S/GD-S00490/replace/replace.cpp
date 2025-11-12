#include<bits/stdc++.h>
using namespace std;
int n,t,ans,l1,l2;
string s[200001],sss[200001],s1,s2;
bool cp(int st,int note)
{
	if(st+s[note].size()-1>=l1)
	{
		//printf("长度不同\n");
		return false;
	}
	//for(int i=st,j=0;j<s[note].size();i++,j++) cout<<s1[i]<<' '<<s[note][j]<<'\n';
	for(int i=st,j=0;j<s[note].size();i++,j++)
		if(s1[i]!=s[note][j])
		{
			//printf("匹配失败\n");
			return false;
		}
	//printf("匹配成功\n");
	return true;
}
void pd(int st,int note)
{
	string ss=s1;
	for(int i=st,j=0;j<sss[note].size();i++,j++) ss[i]=sss[note][j];
	//cout<<ss<<' '<<s2<<'\n';
	if(ss==s2) ans++;
}
int main()
{
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>sss[i];
	}
	while(t--)
	{
		cin>>s1>>s2;
		l1=s1.length(),l2=s2.length();
		if(l1!=l2)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		for(int i=0;i<l1;i++)
		{
			for(int j=1;j<=n;j++)
				if(cp(i,j))
					pd(i,j);
		}
		printf("%d\n",ans);
		//printf("-------------------------\n");
	}
}
/*
不会写
随便打打暴力枚举对比 
期望得个10~30pts吧QAQ 
*/
//I think I may be 3~2=
//QAQ
//freeopen(免费开启) 
//froepen
//freopen
//zto 大佬们 orz 
