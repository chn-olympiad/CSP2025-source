#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string s1[N],s2[N],t1,t2;
unordered_map<string,bool>ljn1;
unordered_map<string,bool>ljn2;
map<pair<int,int>,bool>flag[N];
int dfs(string q1,string q2,int l,int r,int m,int t)
{
	if(l<0||r>m)
	{
		return 0;
	}
	int res=0;
	if(ljn1[q1]&&ljn2[q2]&&!flag[t][{l,r}])
	{
		flag[t][{l,r}]=true;
		res++;
	}
	if(l==0)	
	{
		res+=dfs(q1+t1[r+1],q2+t2[r+1],l,r+1,m,t);
	}
	else
	{
		if(r==0)
		{
			res+=dfs(t1[l-1]+q1,t2[l-1]+q2,l-1,r,m,t);
		}
		else
		{
			res+=dfs(q1+t1[r+1],q2+t2[r+1],l,r+1,m,t)+dfs(t1[l-1]+q1,t2[l-1]+q2,l-1,r,m,t);
		}
	}
	return res;
}
int main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		ljn1[s1[i]]=true;
		ljn2[s2[i]]=true;
	}
	while(q--)
	{
		cin>>t1>>t2;
		int n1=t1.size(),n2=t2.size(),l,r;
		if(n1!=n2)
		{
			printf("0\n");
			continue;
		}
		int m=n1;
		for(int i=0;i<m;i++)
		{
			if(t1[i]!=t2[i])
			{
				l=i;
				break;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(t1[m-i]!=t2[m-i])
			{
				r=m-i;
				break;
			}
		}
		string q1,q2;
		for(int i=l;i<=r;i++)
		{
			q1+=t1[i];
			q2+=t2[i];
		}
		printf("%d\n",dfs(q1,q2,l,r,m,q));
	}
	return 0;
}//1010