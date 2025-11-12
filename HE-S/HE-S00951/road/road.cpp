#include<bits/stdc++.h>
using namespace std;
int n,m,k,q=0,a=0,x=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	int u[m],v[m],w[m],c[k],t[k][n],p[m];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		q+=w[i];
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(w[i]<w[j]){
				a=w[i];
				w[i]=w[j];
				w[j]=a;
				a=u[i];
				u[i]=u[j];
				u[j]=a;
				a=v[i];
				v[i]=v[j];
				v[j]=a;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==1){
			q+=w[i];
			p[x]=i;
			x++;
		}else{
			for(int j=1;j<=x;j++){
				if(u[i]==u[p[x]]&&u[i]==v[p[x]]&&v[i]==u[p[x]]&&v[i]==v[p[x]]){
					i++;
					i--;
				}else{
					q+=w[i];
					p[x]=i;
					x++;
					break;
				}
			}
			
		}
		
	}*/
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
