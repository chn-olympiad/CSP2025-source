#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int ans;
int main(){
	//freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	long long n,m,k,sum = 0;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int x1,y1,v;
		cin>>x1>>y1>>v;
		a[x1][y1] = v;
		a[y1][x1] = v;
		ans+=v;
	}
	for(int i = 1;i<=n-2;i++){
		for(int j =i+1;j<=n-1;j++){
			for(int k = j+1;k<=n;k++){
				if(a[i][k]>0&&a[i][j]>0&&a[j][k]>0){ 
					if(a[i][k] == max(max(a[i][k],a[i][j]),a[j][k])){
						sum+=a[i][k];
						a[i][k] = 0;
					}else if(a[i][j] == max(max(a[i][k],a[i][j]),a[j][k])){
						sum+=a[i][j];
						a[i][j] = 0;
					}else{
						sum+=a[j][k];
						a[j][k] = 0;
					}
				}
			}
		}
	}
	cout<<ans-sum;
	return 0;
} 
