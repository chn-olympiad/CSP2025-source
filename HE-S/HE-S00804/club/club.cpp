#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T;
int n;
int a[N][4];
int p[N],siz[N],b[N];
int ans;

void Solve(){
	ans=0; siz[1]=siz[2]=siz[3]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		int mx=-1;
		for(int j=1;j<=3;j++) mx=max(mx,a[i][j]);
		for(int j=1;j<=3;j++){
			if(a[i][j]==mx){
				p[i]=j; siz[j]++;
				break;
			}
		}
		ans+=mx;
	}
	int num=0;
	for(int i=1;i<=3;i++){
		if(siz[i]>n/2) num=i;
	}
	if(!num){
		printf("%d\n",ans);
		return ;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(p[i]!=num) continue;
		if(num==1) b[++tot]=max(a[i][2],a[i][3])-a[i][1];
		if(num==2) b[++tot]=max(a[i][1],a[i][3])-a[i][2];
		if(num==3) b[++tot]=max(a[i][1],a[i][2])-a[i][3];
	}
	sort(b+1,b+1+tot);
	for(int i=n/2+1;i<=siz[num];i++) ans+=b[i];
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) Solve();	
	return 0;
}
