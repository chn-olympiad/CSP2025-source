#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int p[1005][1005];
int c1[15],c2[15][1005],cs[1005],r[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b>>p[a][b];
		p[b][a]=p[a][b];
	}
	for(int i=1;i<=k;i++){
		cin>>c1[i];
		for(int j=1;j<=n;j++){
			cin>>c2[i][j];
		}
	}
	for(int i=2;i<=n;i++){
		if(p[i][i-1]){
			int a=1e9;
			int q;
			for(int j=1;j<=k;j++){
				if(c2[j][i]+c2[j][i-1]<a){
					a=c2[j][i]+c2[j][i-1];
					q=j;
				}	 
			}
			if(a<p[i][i-1]){
				cs[i]=a+cs[i-1];
				r[q]+=p[i][i-1]-a;
			}else{
				cs[i]=p[i][i-1]+cs[i-1];
			}
		}else{
			int a=1e9;
			int q;
			for(int j=1;j<=k;j++){
				if(c2[j][i]+c2[j][i-1]<a){
					a=c2[j][i]+c2[j][i-1];
					q=j;
				}
				//r[q]+=a; 
			}
			cs[i]=a+cs[i-1];
		}
	}
	for(int i=1;i<=k;i++){
		if(r[i]){
			cs[n]+=min(r[i],c1[i]);
		}
	}
	cout<<cs[n];
	return 0;
}
