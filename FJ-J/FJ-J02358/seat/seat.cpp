#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1e6+10;
using namespace std;
struct node {
	int id,a;
}owo[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(const node x,const node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n=read(),m=read();
	for (int i=1;i<=n*m;++i)
	{
		owo[i].a=read();
		owo[i].id=i;
	}
	
	sort(owo+1,owo+(n*m)+1,cmp);
	
	int num=1;
	for (;num<=n*m;++num)
		if (owo[num].id==1)
			break;
	int ans1=(num/n)+(bool)(num%n),
		p=(num%n)?(num%n):(n),
		ans2=(ans1&1)?(p):(m-p+1);
	printf("%d %d\n",ans1,ans2);
} 
