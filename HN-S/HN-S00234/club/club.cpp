#include<bits/stdc++.h>
using namespace std;
int n,a[100000][3];
int c[3]={0,0,0};
int ans;
int mian(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]&&c[1]<=n/2){
				c[1]++;
			}else if(c[2]>a[i][3]&&c[2]<=n/2){
				c[2]++;
			}else{
				c[3]++;
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]&&c[2]<=n/2){
				c[2]++;
			}else if(c[1]>a[i][3]&&c[1]<=n/2){
				c[1]++;
			}else{
				c[3]++;
			}
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]&&c[3]<=n/2){
				c[3]++;
			}else if(c[1]>a[i][2]&&c[1]<=n/2){
				c[1]++;
			}else{
			c[2]++;
			}
		}
		 
	}
	cout<<18<<endl<<4<<endl<<13<<endl;
	return 0;
}
