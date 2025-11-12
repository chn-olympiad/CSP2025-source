#include<bits/stdc++.h>
using namespace std;
int rd(){
	int re=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')re=(re<<1)+(re<<3)+(c-'0'),c=getchar();
	return f*re;}
int n,a[100005][5],ans,now,c[100005],aa[100005];
void dfs(int x,int y,int z){
	int q=x+y+z;
	if(q==n){ans=max(ans,now);return;}
	if(x<n/2&&a[q+1][1]>0){
		now+=a[q+1][1];
		dfs(x+1,y,z);
		now-=a[q+1][1];}
	if(y<n/2&&a[q+1][2]>0){
		now+=a[q+1][2];
		dfs(x,y+1,z);
		now-=a[q+1][2];}
	if(z<n/2&&a[q+1][3]>0){
		now+=a[q+1][3];
		dfs(x,y,z+1);
		now-=a[q+1][3];}
}bool z,A;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd();
	while(t--){
		A=z=1;n=rd(),ans=0,now=0;
		for(int i=1;i<=n;i++){
			if(a[i][3]>0)z=0;
			if(a[i][3]>0||a[i][2]>0)A=0;
			a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();}
		if(A){
			for(int i=1;i<=n;i++)aa[i]=a[i][1];
			sort(aa+1,aa+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=aa[i];
		}
		else if(z){
			for(int i=1;i<=n;i++)ans+=a[i][2],c[i]=a[i][1]-a[i][2];
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=c[i];
		}
		else dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}