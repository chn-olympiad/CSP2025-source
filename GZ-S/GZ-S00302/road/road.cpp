//GZ-S00302 都匀二中 潘祖镇 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10005],v[10005],w[1000005],c[15],a[10005];
int ANS=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ANS+=w[i];
		
	}
	int temp;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(w[j]>w[i]){
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j]; 
		
		}
		for(int k=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]>a[k]){
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;
			}
		}
		int ans=0,cout=0;
		for(int j=1;j<=m;j++){
			
		for(int k=1;k<=n;k++){
			ans+=c[i];
			if(a[k]<w[j]&&cout<m){
				ans+=a[k];
			}
			else if(cout<m)ans+=w[j];
		}
	}
	if(ans<ANS){
		ANS=ans;
	}
	}
	
	
	}
	
	cout<<ANS;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
