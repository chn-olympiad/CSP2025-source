#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int N=2007;
ULL h1[N][N],h2[N][N];
const ULL P=131;
int n,q;
char s1[N][N],s2[N][N];
ULL p[N];
char t1[N],t2[N];
ULL hx1[N],hx2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<N;i++)
	p[i]=p[i-1]*P;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]+1>>s2[i]+1;
		for(int j=1;j<=strlen(s1[i]+1);j++)
		{
			h1[i][j]=h1[i][j-1]*P+s1[i][j];
			h2[i][j]=h2[i][j-1]*P+s2[i][j];
		//	cout<<h1[i][j]<<' '<<h2[i][j]<<endl;
		}
	}
	while(q--)
	{
		cin>>t1+1>>t2+1;
		for(int i=1;i<=strlen(t1+1);i++)
		hx1[i]=hx1[i-1]*P+t1[i],hx2[i]=hx2[i-1]*P+t2[i];
		int res=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j+strlen(s1[i]+1)-1<=strlen(t1+1);j++)
			{
				int k=j+strlen(s1[i]+1)-1;
				if(hx1[j-1]==hx2[j-1]&&hx1[strlen(t1+1)]-hx1[k]*p[strlen(t1+1)-k]==hx2[strlen(t1+1)]-hx2[k]*p[strlen(t1+1)-k])
				{
					ULL xx=hx1[k]-hx1[j-1]*p[k-j+1];
					ULL yy=hx2[k]-hx2[j-1]*p[k-j+1];
					if(xx==h1[i][strlen(s1[i]+1)]&&yy==h2[i][strlen(s1[i]+1)])
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}



