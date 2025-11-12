#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>10){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int n;
int bes[100005];
int nxt[100005];
int a[5][100005];
int c[5];
int v[100005];
int main(){
	freopen("club.in","r",stdin);
//	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		c[1]=0;
		c[2]=0;
		c[3]=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			a[1][i]=read();
			a[2][i]=read();
			a[3][i]=read();
			if(a[1][i]>=max(a[2][i],a[3][i])){
				bes[i]=1;
				nxt[i]=a[1][i]-max(a[2][i],a[3][i]);
			}else if(a[2][i]>=max(a[1][i],a[3][i])){
				bes[i]=2;
				nxt[i]=a[2][i]-max(a[1][i],a[3][i]);
			}else{
				bes[i]=3;
				nxt[i]=a[3][i]-max(a[1][i],a[2][i]);
			}
			c[bes[i]]++;
			ans+=a[bes[i]][i];
		}
		if(max(max(c[1],c[2]),c[3])>n/2){
			int flag=0;
			if(c[1]>n/2){
				flag=1;
			}else if(c[2]>n/2){
				flag=2;
			}else{
				flag=3;
			}
			int m=max(max(c[1],c[2]),c[3])-n/2;
			for(int i=1;i<=n;i++){
				if(flag!=bes[i]){
					nxt[i]=1919810;
				}
			}
			sort(nxt+1,nxt+n+1);
			for(int i=1;i<=m;i++){
				ans-=nxt[i];
			}
		}
		write(ans);
		putchar('\n');
		
	}
	return 0;
}
