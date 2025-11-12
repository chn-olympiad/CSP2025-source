#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,q1[N],h1[N],l[N],ii,jj,ll,ans;
string s1[N],s2[N],a1,a2;
int pd(int k,int ll)
{
	int b1,b2,iii=ii-q1[k];
	if((jj-ii)!=(h1[k]-q1[k])||iii<0||iii+l[k]>ll)
		return 0;
	for(int i=0;i<l[k];i+=1)
	{
		if(a1[iii+i]!=s1[k][i]||a2[iii+i]!=s2[k][i])
		{
			return 0;
		}
	}	
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i+=1)
	{
		cin>>s1[i]>>s2[i];
		ii=0,jj=s1[i].size(),l[i]=jj;
		jj-=1;
		while(s1[i][ii]==s2[i][ii]&&ii<jj)
			ii+=1;
		while(s1[i][jj]==s2[i][jj]&&jj>=ii+1)
			jj-=1;
		q1[i]=ii,h1[i]=jj;
	}
	while(q--)
	{
		cin>>a1>>a2;
		ii=0,jj=a1.size(),ll=jj,ans=0;
		jj-=1;
		while(a1[ii]==a2[ii]&&ii<jj)
			ii+=1;
		while(a1[jj]==a2[jj]&&jj>=ii+1)
			jj-=1;	
		for(int i=1;i<=n;i+=1)
			ans+=pd(i,ll);
		cout<<ans<<endl; 
	}
	return 0;
}