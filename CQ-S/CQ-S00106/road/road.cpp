#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,k,d,e,f,fy=0,fmini=INT_MAX;
unsigned long long a[10005][10005],c[10005],c1[10005];
unsigned long long a1[10005][10005],flag[10005];
void z(unsigned long long i,unsigned long long p){
	for(unsigned long long j=1;j<=k+m;j++){
		if(a1[p][j]>0 && a1[i][j]==0){
			a1[i][j]=1;
			a1[j][i]=1;
		}
		if(a1[i][j]>0 && a1[p][j]==0){
			a1[p][j]=1;
			a1[j][p]=1;
		}
	}
}
int stt(){
	unsigned long long sum=0;
	for(unsigned long long i=1;i<=n;i++){
		for(unsigned long long j=1;j<=n;j++){
			cout<<a1[i][j]<<' ';
			if(a1[i][j]>0){
				sum++;
			}
		}
		cout<<endl;
	}
	cout<<sum<<' ';
	if(sum+n/2>n*n) return true;
	return false;
}
void dfs(unsigned long long step){
	if(stt()){
		for(unsigned long long i=1;i<=k;i++){
			if(c1[i]==1) fy+=c[i];
		}
		if(fmini>fy){
			fmini=fy;
		}
		return;
	}
	for(unsigned long long i=1;i<=n+m;i++){
		for(unsigned long long l=1;l<=i;l++){
			for(unsigned long long j=l;j<=i;j++){
				if(a[step][j]==0){
					continue;
				}
				if(a1[step][j]==0 && a1[j][step]==0){
					flag[j]=1;
					a1[step][j]=1;
					a1[j][step]=1;
					z(step,j);
					fy+=a[step][j];
					if(j>n) c1[j-n]=1;
					dfs(step+1);
				}
			}
			for(unsigned long long j=1;j<=i;j++){
				if(flag[j]==1){
					flag[j]=0;
					a1[step][j]=0;
					a1[j][step]=0;
					fy-=a[step][j];
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(unsigned long long i=1;i<=m;i++){
		cin>>d>>e>>f;
		a[d][e]=f;
		a[e][d]=f;
	}
	for(unsigned long long i=1;i<=k;i++){
		cin>>c[i];
		for(unsigned long long j=1;j<=n;j++){
			cin>>a[i+n][j];
			a[j][i+n]=a[i+n][j];
		}
	}
	for(unsigned long long i=1;i<=n+k;i++){
		a1[i][i]=1;
	}
	dfs(1);
	cout<<fmini;
	return 0;
}
