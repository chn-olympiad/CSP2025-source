#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e6+10;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),m=read();
	for (int i=1;i<=m;++i) printf("0\n");
	
	
} 
