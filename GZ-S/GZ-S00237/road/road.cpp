//GZ-S00237 贵阳市为明高级中学 李竹风 
#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int b[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=1;i<=m;i++){
	int l,r,y;
	cin>>l>>r>>y;
	a[l][r]=y;
	a[r][l]=y;
	}
	int sum=0;
	if(k==0){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				sum+=a[i][j];
			}
		}
		cout<<sum/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
