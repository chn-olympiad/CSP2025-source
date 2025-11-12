#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int in(){
	int x=0;
	int f=1;
	char c;
	c=getchar();
	while(c!='-'&&(!(c>='0'&&c<='9'))) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
	return x;
}
int n,T;
int a[N][4];
int f[210][110][110];
int used[N];
struct aval{
	int val,an,pos,minn;
}d[N*3];
bool cmp(aval x,aval y){
	return x.val>y.val;
}
void solve1(){
	memset(f,0,sizeof(f));
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i-j-k<0||i-j-k>n/2) continue;
				if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if(i-j-k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
			}
		}
	}
	for(int i=0;i<=n/2;i++)
	for(int j=0;j<=n/2;j++){
		if(n-j-i<0||n-j-i>n/2) continue;
		ans=max(ans,f[n][i][j]);
		
	}
	printf("%d\n",ans);
}
void solve2(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++) used[++cnt]=-a[i][1];
	sort(used+1,used+cnt+1);
	for(int i=1;i<=n/2;i++) ans+=-used[i];
	printf("%d\n",ans);
}
void solve3(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		d[++cnt].val=a[i][1]-a[i][2];
		d[cnt].pos=i;
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			ans+=a[d[i].pos][1];
		}else{
			ans+=a[d[i].pos][2];
		}
	}
	printf("%d\n",ans);
}
void solve4(){
	memset(used,0,sizeof(used));
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		int minn=min(a[i][1],min(a[i][2],a[i][3]));
		a[i][1]-=minn;a[i][2]-=minn;a[i][3]-=minn;
		d[++cnt].an=1;d[cnt].minn=minn;d[cnt].pos=i;d[cnt].val=a[i][1];
		d[++cnt].an=2;d[cnt].minn=minn;d[cnt].pos=i;d[cnt].val=a[i][2];
		d[++cnt].an=3;d[cnt].minn=minn;d[cnt].pos=i;d[cnt].val=a[i][3];
	}
	sort(d+1,d+cnt+1,cmp);
	int cntp[5];
	cntp[1]=cntp[2]=cntp[3]=0;
	for(int i=1;i<=cnt;i++){
		if(used[d[i].pos]==0&&cntp[d[i].an]<n/2){
			used[d[i].pos]=1;
			cntp[d[i].an]++;
			ans+=d[i].val+d[i].minn;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=in();
	while(T--){
		int A,B;
		A=B=1;
		n=in();
		for(int i=1;i<=n;i++) a[i][1]=in(),a[i][2]=in(),a[i][3]=in();
		for(int i=1;i<=n;i++){
			if(a[i][3]!=0) A=0,B=0;
			if(a[i][2]!=0) A=0;
		}
		if(n<=200)solve1();
		else if(A)solve2();
		else if(B)solve3();
		else solve4();
	}
	return 0;
}