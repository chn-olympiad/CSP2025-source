#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,M=2e5+5;
int n,q,siz[M];
char a[N],b[N];
int ans;
unsigned long long ha[N],hb[N],hs[N],hq[N],m[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a+1>>b+1;
		siz[i]=strlen(a+1);
		for(int j=1;j<=strlen(a+1);j++)
			ha[i]=ha[i]*233+a[j]-'a',m[i]*=233;
		for(int j=1;j<=strlen(b+1);j++)
			hb[i]=hb[i]*233+b[j]-'a';
	 } 
	 for(int i=1;i<=q;i++)
	 {
	 	ans=0;
	 	cin>>a+1>>b+1;
	 	int l=strlen(a+1);
	 	for(int j=1;j<=strlen(a+1);j++)
	 		hs[j]=hs[j-1]*233+a[j]-'a';
	 	for(int j=1;j<=strlen(b+1);j++)
	 		hq[j]=hq[j-1]*233+b[j]-'a';
	 	for(int j=1;j<=l;j++)
	 	{
	 		for(int k=1;k<=n;k++)
	 		{
	 			if(j+siz[k]-1<=l)
	 			{
	 				int r=j+siz[k]-1;
	 				if(ha[k]==hs[r]-hs[j-1]*m[k]&&hb[k]==hq[r]-hq[j-1]*m[k]&&hs[j]==hq[j])
	 				{
	 					ans++;
	 					continue;
					 }
				 }
			 }
		 }
		 cout<<ans<<'\n';
	 }
	return 0;
}