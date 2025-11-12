#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=200005;
const int jz1=20101011,jz2=20101220;
int n,q,len[N],ans;
string a,b;
inline string read()
{
	string s;
	char ai=getchar();
	while(ai<'a'||ai>'z') ai=getchar();
	while(ai>='a'&&ai<='z') s+=ai,ai=getchar();
	return s;
}
vector<ull> ls1,ls2,ls11,ls22;
ull pw1[5000005],pw2[5000005],hsa[N],hsb[N],hsa1[N],hsb1[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=5000000;i++) pw1[i]=pw1[i-1]*jz1,pw2[i]=pw2[i-1]*jz2;
	for(int i=1;i<=n;i++)
	{
		a=read(),b=read();len[i]=a.size();
//		cout<<a<<' '<<b<<endl;
		hsa[i]=a[0]-'a',hsb[i]=b[0]-'a'; 
		for(int j=1;j<len[i];j++)
			hsa[i]=hsa[i]*jz1+(a[j]-'a'),hsb[i]=hsb[i]*jz1+(b[j]-'a');
		hsa1[i]=a[0]-'a',hsb1[i]=b[0]-'a'; 
		for(int j=1;j<len[i];j++)
			hsa1[i]=hsa1[i]*jz2+(a[j]-'a'),hsb1[i]=hsb1[i]*jz2+(b[j]-'a');
//		printf("%d %llu %llu\n",i,hsa[i],hsb[i]);
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		a=read(),b=read();
		int xlen=a.size(),pd=(a!=b);
		ls1.clear(),ls2.clear(),ls11.clear(),ls22.clear();
		ls1.push_back(a[0]-'a'),ls2.push_back(b[0]-'a'); 
//		cout<<a<<' '<<b<<endl;
		for(int j=1;j<xlen;j++)
			ls1.push_back(ls1.back()*jz1+(a[j]-'a')),ls2.push_back(ls2.back()*jz1+(b[j]-'a'));
		ls11.push_back(a[0]-'a'),ls22.push_back(b[0]-'a'); 
//		cout<<a<<' '<<b<<endl;
		for(int j=1;j<xlen;j++)
			ls11.push_back(ls11.back()*jz2+(a[j]-'a')),ls22.push_back(ls22.back()*jz2+(b[j]-'a'));
//		for(int j=0;j<xlen;j++) cout<<ls1[j]<<' '<<ls2[j]<<endl;
//		cout<<endl;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=xlen-len[j];k++)
			{
				if(k>0&&(ls1[k-1]!=ls2[k-1]||ls11[k-1]!=ls22[k-1])) break;
				if(k<xlen-len[j]&&((ls1[xlen-1]-ls1[k+len[j]-1]*pw1[xlen-1-(k+len[j]-1)])!=(ls2[xlen-1]-ls2[k+len[j]-1]*pw1[xlen-1-(k+len[j]-1)])
				||(ls11[xlen-1]-ls11[k+len[j]-1]*pw2[xlen-1-(k+len[j]-1)])!=(ls22[xlen-1]-ls22[k+len[j]-1]*pw2[xlen-1-(k+len[j]-1)]))) continue;
//				cout<<j<<' '<<k<<' '<<k+len[j]-1<<endl;
				ull ua=ls1[k+len[j]-1]-(k>0?ls1[k-1]*pw1[k+len[j]-1-(k-1)]:0),ub=ls2[k+len[j]-1]-(k>0?ls2[k-1]*pw1[k+len[j]-1-(k-1)]:0);
				ull ua2=ls11[k+len[j]-1]-(k>0?ls11[k-1]*pw2[k+len[j]-1-(k-1)]:0),ub2=ls22[k+len[j]-1]-(k>0?ls22[k-1]*pw2[k+len[j]-1-(k-1)]:0);
				if(ua==hsa[j]&&ub==hsb[j]&&ua2==hsa1[j]&&ub2==hsb1[j]) 
				{
					ans++;	
					if(pd) break;
				}
//				cout<<ua<<' '<<ub<<' '<<ans<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

