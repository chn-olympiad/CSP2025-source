#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[100000][1000000];
	n%2==0;
	cin>>t>>n;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int d[1],v[2],e[3],max1,max2,max3;
	while(d[1]<=n&&d[2]<=n&&d[3]<=n){
		if(d[1]>v[2]&&d[1]>e[3]){
			max1++;
		}
		if(v[2]>d[1]&&v[2]>e[3]){
			max2++;
		}
		else{
			max3++;
		}
	}
	cout<<max1+max2+max3; 
	return 0;
} 
