#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
long long a[100005][3],a1[15][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= 3;j++)
			cin>>a[i][j];
	for(int i = 1;i <= k; i++)
		for(int j = 1; j <= n ;j++)
			cin>>a1[i][j];
	if(k==0){
	int sum = 0;
		if(n%2==0){
			int minn = 100000000;
			for(int i = 1;i <= m;i++){
				if(a[i][2]-a[i][1]==1||a[i][1]-a[i][2]==1||abs(a[i][1]-a[i][2]==n-1)){
					if(minn>a[i][3]){
						minn=a[i][3];
					}
				}else{
					sum+=a[i][3];	
				}
			}
			sum+=minn;
		}else{
			for(int i = 1;i <= m;i++){
				if(a[i][2]-a[i][1]==1||a[i][1]-a[i][2]==1){
					continue;
				}else{
					sum+=a[i][3];
				}
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
