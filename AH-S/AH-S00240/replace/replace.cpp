#include<bits/stdc++.h>
using namespace std;
int n,q,ans,ans1;
map<string,string> b;
void dfs(int l,int r,string q,string p,string s1,string s2,int num1,int num2)
{
	int len=s1.size(),op=q.size();
	if(b[q]==p&&(l==num1||r==num2)) ans++;
	else if(b[q]==p) ans1++;
	if(len==op) return;
	if(r+1<len)
	{
		q+=s1[r+1];
		p+=s2[r+1];
		dfs(l,r+1,q,p,s1,s2,num1,num2);
	}
	if(l-1>=0)
	{
		string op1="",op2="";
		op1+=s1[l-1];
		op2+=s2[l-1]; 
		op1+=q;
		op2+=p;
		dfs(l-1,r,op1,op2,s1,s2,num1,num2);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string ss1="",ss2="";
		cin>>ss1>>ss2;
		b[ss1]=ss2;
		b[ss2]=ss1;
	}
	for(int i=1;i<=q;i++)
	{
		ans=ans1=0;
		string s1="",s2="",s11="",s22="";
		int num1=0,num2=0;
		cin>>s1>>s2;
		int len1=s1.size();
		for(int j=0;j<len1;j++)
		{
			if(s1[j]=='b') num1=j;
			if(s2[j]=='b') num2=j;
			if(num1!=0&&num2!=0) break;
			if(j==len1-1) num1=num2=max(num1,num2);
		}
		for(int j=min(num1,num2);j<=max(num1,num2);j++) s11+=s1[j],s22+=s2[j];
		//if(b[s11]==s22) ans++;
		dfs(min(num1,num2),max(num1,num2),s11,s22,s1,s2,num1,num2);
		printf("%d\n",ans+ans1/2);
	}
	return 0;
}
