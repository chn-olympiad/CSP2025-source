#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000010],x[1000010],y[1000010],xx[10],xy[10][1000010],aa[1000010],nn[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>x[i]>>y[i];
		aa[i]=a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>xx[i];
		for(int j=1;j<=n;j++){
			cin>>xy[i][j];
		}
	}
	int cnt=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			cnt=cnt+a[i];
			for(int j=1;j<=m;j++){
				if(a[i]==aa[j]){
					nn[x[j]]=1;
					nn[y[j]]=1;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(nn[j]==0){
					break;
				}
				if(j==n){
					cout<<cnt;
					return 0;
				}
			}
		} 
	return 0;
} 

