#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long k[5],sum[10]={0};
	long a[100005][5];
	int t,n;
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				k[i]=1;
			}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				k[i]=2;
			}else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				k[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			sum[j]+=a[i][k[i]];
		}
	}
	for(int i=1;i<=t;i++){
		if(i==2){
			sum[i]-=2;
		}
		if(i==3){
			sum[i]-=1;
		}
		cout<<sum[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
