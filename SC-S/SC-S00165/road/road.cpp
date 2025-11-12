 #include<bits/stdc++.h>
 using namespace std;
 long long n,m,k,v[100010],u[100010];
 long long c[15],a[15][101],w[100010],ans[15],mi[15];
 bool b[100010];
 long long txr;
 
 int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=1;i<=n;i++){
 		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		cin>>a[j][1];
		mi[j]=a[j][1];
		for(int l=2;l<=n;l++){
			cin>>a[j][l];
			if(a[j][l]<=mi[j]){
				mi[j]=a[j][l];
			}
		}
	}
	for(int i=1;i<=k;i++){
		ans[i]+=c[i];
		for(int j=1;j<=n;j++){
			if(b[v[i]]==0||b[u[i]]==0){
				ans[i]+=min(w[j],a[i][u[i]]+a[i][v[i]]);
				b[v[i]]=b[u[i]]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				ans[i]+=a[i][j];
				ans[i]+=mi[i];
			}
		}
	}
	txr=ans[1];
	for(int i=2;i<=k;i++){
		txr=min(txr,ans[i]);
	}
 	cout<<txr;
 	
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 } 