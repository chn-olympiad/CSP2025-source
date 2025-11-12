#include<bits/stdc++.h>
using namespace std;
int n,k,pt,xsum[500001],lst[1048576],pos[1048576],ans;
inline int read()
{
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c&15),c=getchar();
	return s;
}
int main()
{
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=0;i<(1<<20);i++) pos[i]=lst[i]=-1;
	pos[0]=0;
	for(int i=1,p;i<=n;i++)
	{
		xsum[i]=xsum[i-1]^read();
		lst[xsum[i]]=pos[xsum[i]],pos[xsum[i]]=i;
		if((k&&pos[xsum[i]]>=pt&&pos[xsum[i]^k]>=pt)||(!k&&pos[xsum[i]]>=pt&&lst[xsum[i]]>=pt)) ans++,pt=i;
	}
	cout<<ans;
}
