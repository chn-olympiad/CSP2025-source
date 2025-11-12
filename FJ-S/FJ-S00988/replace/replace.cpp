#include<bits/stdc++.h>
using namespace std;
int n,q;
int len[200020];
string s1[200020],s2[200020];
char t1[5000020],t2[5000020],T1[5000020];
int nex[5000020];
int kmp(string a,string b)
{
	int lena=a.size(),lenb=b.size(),j=-1;
	memset(nex,-1,sizeof(nex));
	for(int i=-1;i+1<lenb;i++)
	{
		while(j!=-1&&b[j+1]!=b[i+1])
			j=nex[j];
		if(b[j+1]==b[i+1])
			nex[i+1]=j+1;
	}
	nex[0]=-1;
	j=-1;
	for(int i=-1;i+1<lena;i++)
	{
		while(j!=-1&&b[j+1]!=a[i+1])
			j=nex[j];
		if(b[j+1]==a[i+1])
			j++;
		if(j==lenb-1)
			return i+1;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		if(strlen(t1)!=strlen(t2))
		{
			cout<<"0\n";
			continue;
		}
		int Len=strlen(t1);
		for(int i=1;i<=n;i++)
		{
			int st=kmp(t1,s1[i]);
			bool flag=1;
//			cout<<st<<endl;
			if(st==-1)
				continue;
			for(int i=0;i<Len;i++)
				T1[i]=t1[i];
			for(int j=0;j<len[i];j++)
				t1[st-j]=s2[i][len[i]-1-j];
			for(int i=0;i<Len;i++)
				if(t1[i]!=t2[i])
				{
					flag=0;
					break;
				}
			if(flag)
				ans++;
			for(int i=0;i<Len;i++)
				t1[i]=T1[i];
		}
		cout<<ans<<"\n";
	}
}
