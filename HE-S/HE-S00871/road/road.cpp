#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10020][10020],b[10020],c[2000010],ans=0,c1,c2=0,ui,vi,wi,cj,cij;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	c1=n+k-1;
	for(int i=1;i<=m;i++){
		cin>>ui>>vi>>wi;
		a[ui][vi]=wi;
		a[vi][ui]=wi;
		b[vi]++;
		b[ui]++;
	}
	for(int j=1;j<=k;j++){
		cin>>cj;
		for(int i=1;i<=n;i++){
			cin>>cij;
			a[n+j][i]=cij;
			a[i][n+j]=cij;
			b[i]++;
		}
		b[n+j]=n;
	}
	for(int i=1;i<=n+k;i++){
		if(b[i]==1){
			for(int j=1;j<=n+k;j++){
				if(a[i][j]!=-1){
					ans+=a[i][j];
					a[i][j]=-1;
					c1--;
				}	
			}
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]!=-1){
				c[c2]=a[i][j];
				c2++;
			}
		}
	}
	sort(c,c+c2);
	for(int i=0;i<c2;i++){
		if(c1){
			ans+=c[i];
			c1--;
		}
	}
	cout<<ans;
	return 0;
}
