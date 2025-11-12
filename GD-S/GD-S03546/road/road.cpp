#include <bits/stdc++.h>
using namespace std;
long long n,m,c[10010][11],f[10010],ans=0,cnt=0;
ifstream fin("road.in");
ofstream fout("road.out");
struct st{
	long long u,v,w;
} a[1600010];
bool cmp(st xx, st yy){
	return xx.w<yy.w;
}
int find1(long long x){
	if(x==f[x]) return x;
	else return f[x]=find1(f[x]);
}
int kru(){
	long long i;
	for(i=1;i<=m;i++){
		int uu,vv;
		uu=find1(a[i].u);
		vv=find1(a[i].v);
		if(uu==vv) continue;
		else{
			f[uu]=vv;
			ans+=a[i].w;
			cnt++;
			if(cnt==n-1){
			fout<<ans;
			return 0;	
			}
		}
	}
	return 0;
} 
int main(){
	long long i,j,k;
	
	fin>>n>>m>>k;
	for(i=1;i<=m;i++){
	 	fin>>a[i].u>>a[i].v>>a[i].w;	
    }
	for(j=1;j<=k;j++){
	 		fin>>c[0][j];
	 		for(int p=1;p<=n;p++) fin>>c[p][j];
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			m=m+1;
			a[m].v=i;
			a[m].u=j;
			a[m].w=LONG_LONG_MAX;
			for(int p=1;p<=k;p++) a[m].w=min(a[m].w,c[i][p]+c[j][p])+c[0][p];
		}
	}
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=n;i++) f[i]=i;
	kru();
	fin.close();
	fout.close();
	return 0;
}
