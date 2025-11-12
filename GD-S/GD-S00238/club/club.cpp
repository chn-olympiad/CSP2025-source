#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	register int fh=1,nbr=0;
	register char ch=getchar();
	while((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if(ch=='-') fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9') nbr=nbr*10+(ch-'0'),ch=getchar();
	return fh*nbr;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	static int stk[21];
	register int top=0;
	while(x) stk[++top]=x%10,x=x/10;
	while(top) putchar(stk[top--]+'0');
}
struct node{
	int x,id,oth;
	bool operator < (const node a)const{
		return x<a.x;
	}
}num[100005];
int t,n,a[100005][4],jl[4],typ[100005],cnt;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) a[i][j]=read();
		jl[1]=jl[2]=jl[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int tmp=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==tmp) jl[1]++,typ[i]=1;
			else if(a[i][2]==tmp) jl[2]++,typ[i]=2;
			else jl[3]++,typ[i]=3;
			ans+=tmp;
		}
		if(jl[1]<=n/2&&jl[2]<=n/2&&jl[3]<=n/2){
			write(ans),putchar('\n');
			continue;
		}
		int col,ot1,ot2;
		if(jl[1]>n/2) col=1,ot1=2,ot2=3;
		if(jl[2]>n/2) col=2,ot1=1,ot2=3;
		if(jl[3]>n/2) col=3,ot1=1,ot2=2;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(typ[i]==col){
				cnt++;
				if(a[i][ot1]>=a[i][ot2]) num[cnt].oth=ot1;
				else num[cnt].oth=ot2;
				num[cnt].x=a[i][col]-a[i][num[cnt].oth];
				num[cnt].id=i;
			}
		}
		sort(num+1,num+1+cnt);
		for(int i=1;i<=cnt-n/2;i++) typ[num[i].id]=num[i].oth,ans-=num[i].x,jl[col]--,jl[num[i].oth]++;
		write(ans),putchar('\n');
	}
	return 0;
}
//Don't have any bugs.
