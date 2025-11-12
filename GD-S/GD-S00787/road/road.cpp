#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[1000001],b[1000001],c[1000001],d[1000001],e[1000001],f,g=1,h,l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++)cin>>e[j+t*n];
		t++;
	}
	for(int i=1;i<=m-1;i++){
		for(int j=i+1;j<=m;j++){
			if(c[j]>c[i]){
				f=a[i];
				a[i]=a[j];
				a[j]=f;
				f=b[i];
				b[i]=b[j];
				b[j]=f;
				f=a[i];
				c[i]=c[j];
				c[j]=f;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(d[g]<c[i]){
			for(int j=1;j<=n*k;j++){
				if(e[j]<c[j]){
					h+=e[j];
					l++;
				}
			}
			h+=d[g];
		}else{
			h+=c[i];
			l++;
		}
		if(l>=n-1){
			cout<<h;
			return 0;
		}
	}
	return 0;
}
