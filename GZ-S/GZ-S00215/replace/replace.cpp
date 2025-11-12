//GZ-S00215 贵阳市第一中学  李啸峰 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,Ans;
string s1,s2,str1[N],str2[N];
int find(string a,string b)
{
	if(a.size()<b.size())
		return -1;
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<=lena-lenb;i++)
	{
		int j=0;
		while(a[i+j]==b[j])
		{
			j++;		
			if(j==lenb)
				return i;
		}
	}
	return -1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>str1[i]>>str2[i];
	for(int i=1;i<=q;i++)
	{
		Ans=0;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++)
		{
			int pos=find(s1,str1[j]);
			if(pos==-1)
				continue;
			string s3="";
			int len=str1[j].size();
			for(int k=0;k<pos;k++)
				s3+=s1[k];
			for(int k=0;k<len;k++)
				s3+=str2[j][k];
			for(int k=pos+len;k<s1.size();k++)
				s3+=s1[k]; 
			if(s2==s3)
				Ans++;
		}
		cout<<Ans<<endl; 
	}
	return 0;
}
