#include<bits/stdc++.h>
typedef long long ll;
const ll maxn=(1<<21)+100;
using namespace std;
int owo[maxn],pre[maxn],qwq[maxn];
struct node {
	int ti,fl;
}bul[maxn];
inline ll read(){
	ll ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n=read(),k=read();
	for (int i=1;i<=n;++i)
		owo[i]=read();

	pre[0]=0;
	for (int i=1;i<=n;++i)
		pre[i]=pre[i-1]^owo[i];
	
	for (int i=1;i<=n;++i)
		qwq[i]=pre[i]^k;
		
		
	for (int i=0;i<=(1<<21)-1;++i)
		bul[i].fl=0,bul[i].ti=0;
	bul[0].fl=1;
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		if (bul[qwq[i]].fl && bul[qwq[i]].ti==ans)
			ans++;
		bul[pre[i]].fl=1,bul[pre[i]].ti=ans;
	}
	printf("%d ",ans);
	
} 
