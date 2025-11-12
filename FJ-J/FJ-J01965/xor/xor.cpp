#include<bits/stdc++.h>
using namespace std;
#define int __int128
int n,k,a[500005],f[500005],cnt,ans=1;
struct c{
	int l,r;
}s[500005];
int read(){
	char ch=getchar();int w=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x/10)write(x/10);
	putchar(x%10+'0');
}
bool xzx(c x,c y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			t^=a[j];
			if(t==k){
				s[++cnt]={i,j};
				break;
			}
		}
	}
	sort(s+1,s+cnt+1,xzx);
	int nxt=cnt;
	for(int i=1;i<=cnt;i=nxt){
		bool f=0;
		for(int j=i+1;j<=cnt;j++)
			if(s[j].l>s[i].r){
				ans++,nxt=j,f=1;
				break;
			}
		if(f==0){
			write(ans);
			return 0;
		}
	}
	return 0;
}
