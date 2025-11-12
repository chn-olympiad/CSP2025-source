#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,a[3][N],cnt[3],v[N],f,b[N],tot,x;
provariety_queue<int> q;
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		f=ans=tot=cnt[0]=cnt[1]=cnt[2]=0,n=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++) a[j][i]=read();
			if(a[0][i]>a[1][i]){
				if(a[0][i]>a[2][i]) ans+=a[0][i],cnt[0]++,v[i]=0;
				else ans+=a[2][i],cnt[2]++,v[i]=2;
			}
			else{
				if(a[1][i]>a[2][i]) ans+=a[1][i],cnt[1]++,v[i]=1;
				else ans+=a[2][i],cnt[2]++,v[i]=2;
			}
		}
		for(int i=0;i<=2;i++) if(cnt[i]>(n/2)) f=1,x=i;
		if(f){
			for(int i=1;i<=n;i++) if(v[i]==x) b[++tot]=a[x][i]-max(a[(x+1)%3][i],a[(x+2)%3][i]);
			sort(b+1,b+tot+1);
			for(int i=1;i<=tot-(n/2);i++) ans-=b[i];
		}
		printf("%d\n",ans);
	}
}
