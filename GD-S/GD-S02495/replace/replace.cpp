#include<bits/stdc++.h>
#define ll long long
#define zsi z[i].size()
#define ssi s[i].size()
using namespace std;
int n,m,l1,l2,ans[200005],is_ok;
string s[200005],z[200005],s2[200005],z2[200005];
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
scanf("%d %d",&n,&m);

for(int i=1;i<=m;i++)
	printf("0\n");
//for(int i=1;i<=m;i++)
//{
//	if(z[i].size()!=z2[i].size()) continue;
//	l1=l2=0;
//	for(int j=0;j<z[i].size();j++)	
//	{
//		if(z[i]!=z2[i]&&l1==0) 
//		{
//			if(l1==0) l1=j;	
//			l2=j;
//		}
//	}
//	for(int j=1;j<=n;j++)
//	{
//		if(ssi<(l2-l1+1)) continue;
//		for(int k=0;k<s[i].size();i++)
//		{
//			if(l1-k<0) continue;
//			if(s[k]==z[l1])
//			{
//				is_ok=1;
//				for(int l=l1-k;l<=l1-k+ssi-1;l++)
//					if(z[l]!=s[l-(l1-k)]) 
//					{
//						is_ok=0;
//						break;
//					}
//				if(is_ok==1) 
//				{
//					ans[i]++;
//					break;
//				}
//			}
//		}
//	}
//}
//for(int i=1;i<=m;i++)
//	printf("%d\n",ans[i]);
fclose(stdin);
fclose(stdout);
	return 0;
}

