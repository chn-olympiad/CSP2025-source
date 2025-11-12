#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,cnt,K[N],f[N],kk,C[20],u[20],used[N];
long long ans;
struct xy{
	int x,y;
};
struct node{
	int x,y,w,num;
}A[2000005];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
inline int read(){
	char ch;
	ch=getchar();
	int x=0,ff=1;
	while(ch<'0' || ch>'9'){
		if(x=='-') ff=-1; 
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*ff;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		//int x,y,z;
		//scanf("%d%d%d",&x,&y,&z);
		kk++;
		A[kk].x=read(),A[kk].y=read(),A[kk].w=read(),A[kk].num=0;
	} 
	for(int i=1;i<=k;i++){
		scanf("%d",&C[i]);
		for(int j=1;j<=n;j++){
			f[j]=j;
			K[j]=read();
			for(int q=1;q<j;q++){
				kk++;
				A[kk].x=j,A[kk].y=q,A[kk].w=K[j]+K[q]+C[i],A[kk].num=i;
			}
		}
		
	}
	sort(A+1,A+kk+1,cmp);
	for(int i=1;cnt<=n-1;i++){
		//printf("%d %d %d\n",A[i].x,A[i].y,A[i].w);
		if(find(A[i].x)!=find(A[i].y)){
			if(A[i].num && u[A[i].num]){
				ans-=C[A[i].num];
			}
			if(A[i].num && !u[A[i].num]){
				u[A[i].num]=1;
			}
			cnt++;
			ans+=A[i].w*1ll;
			f[find(A[i].y)]=find(A[i].x);
		}
		if(i>kk) break;
	}
	cout<<ans;
}
