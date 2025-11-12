#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10,T=15;
int a1[M],b1[M],c1[M];
int a2[M],b2[M],c2[M];
void qsort(int l,int r)
{
	if(l==r) return ;
	int mid=(l+r)>>1;
	int lt=l-1,rt=l-1;
	qsort(l,mid); qsort(mid+1,r);
	for(int i=mid+1;i<=r;i++){
		while(lt<mid&&c1[lt+1]<=c1[i]){
			lt++; rt++; c2[rt]=c1[lt]; b2[rt]=b1[lt]; a2[rt]=a1[lt];
		}
		rt++; c2[rt]=c1[i]; b2[rt]=b1[i]; a2[rt]=a1[i];
	}
	while(lt<mid){
		lt++; rt++; c2[rt]=c1[lt]; b2[rt]=b1[lt]; a2[rt]=a1[lt];
	}
	for(int i=l;i<=r;i++){
		c1[i]=c2[i]; b1[i]=b2[i]; a1[i]=a2[i];
		c2[i]=0; b2[i]=0; a2[i]=0;
	}
	return ;
}
int fath[N];
int find(int x)
{
	if(fath[x]!=x) return fath[x]=find(fath[x]);
	else return x;
}
int n,m,k,L; 
int vt[T],lth,ps[T];
void getp()
{
	ps[1]=1; for(int i=2;i<=k+1;i++) ps[i]=ps[i-1]*2; L=ps[k+1]-1;
	return ;
}
int val[T],cs[T][N];
int a[N],b[N],c[N];
int u[N],v[N],w[N];
bool note[T][N]; int mnn[N],id[N],cst[T][T],g[T][T];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k); getp();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a1[i],&b1[i],&c1[i]);
	}
	qsort(1,m);
	for(int i=1;i<=n;i++) fath[i]=i;
	int ltf=0;
	for(int i=1;i<=m;i++){
		int tx=find(a1[i]),ty=find(b1[i]);
		if(tx==ty) continue ;
		ltf++; a[ltf]=a1[i]; b[ltf]=b1[i]; c[ltf]=c1[i]; fath[ty]=tx;
	}
	for(int i=1;i<=m;i++) a1[i]=0,b1[i]=0,c1[i]=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&cs[i][j]);
			a1[(i-1)*n+j]=i; b1[(i-1)*n+j]=j; c1[(i-1)*n+j]=cs[i][j];
		}
	}
	qsort(1,k*n);
	for(int i=1;i<n;i++) ans=ans+c[i]; 
	for(int i=1;i<=L;i++){
		long long sum=0;
		for(int j=1;j<=k;j++){
			if(i&ps[j]){
				vt[++lth]=j; sum=sum+val[j];
			}
		}
		for(int j=1;j<=lth;j++){
			for(int p=1;p<=lth;p++){
				cst[vt[j]][vt[p]]=1e9+7; g[vt[j]][vt[p]]=0;
			}
		}
		for(int j=1;j<=n;j++){
			mnn[j]=1e9+7; id[j]=0;
			for(int p=1;p<=lth;p++){
				if(cs[vt[p]][j]<mnn[j]){
					mnn[j]=cs[vt[p]][j]; id[j]=vt[p];
				}
			}
			note[id[j]][j]=true;
			for(int p=1;p<=lth;p++){
				if(vt[p]==id[j]) continue ;
				if(cs[vt[p]][j]<cst[id[j]][vt[p]]){
					cst[id[j]][vt[p]]=cs[vt[p]][j];
					g[id[j]][vt[p]]=j;
				}
			}
		}
		for(int j=1;j<=lth;j++){
			for(int p=1;p<=lth;p++){
				if(vt[j]==vt[p]) continue ;
				note[vt[p]][g[vt[j]][vt[p]]]=true;
			}
		}
		int len=0,tx=0,ty=0,lt=0,cnt=0;
		for(int j=1;j<=k*n;j++){
			if(note[a1[j]][b1[j]]){
				len++; u[len]=a1[j]+n; v[len]=b1[j]; w[len]=c1[j];
			}
		}
		for(int j=1;j<=n+k;j++){
			fath[j]=j;
		}
		for(int j=1;j<=n-1;j++){
			while(lt<len&&w[lt+1]<c[j]){
				lt++; tx=find(u[lt]),ty=find(v[lt]);
				if(tx==ty) continue ;
				cnt++; fath[ty]=tx; sum=sum+w[lt];
				if(cnt==n+lth-1) break;
			}
			if(cnt==n+lth-1) break;
			tx=find(a[j]),ty=find(b[j]);
			if(tx==ty) continue ;
			cnt++; fath[ty]=tx; sum=sum+c[j];
			if(cnt==n+lth-1) break;
		}
		for(int j=1;j<=len;j++){
			note[u[j]-n][v[j]]=false; u[j]=0,v[j]=0; 	
		}
		for(int j=1;j<=lth;j++) vt[j]=0;
		lth=0; ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
} 
