#include<bits/stdc++.h>
#define long long int
using namespace std;
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a[n][3],b[m][5];
	int sum=0,summ=0;
	for(int i=0;i<m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(i<=n){
			sum+=a[i][3];
		}
	}
	for(int i=0;i<k;i++){
		cin>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4]>>b[i][5];
	}
	cout<<sum;
	return 0;
}

