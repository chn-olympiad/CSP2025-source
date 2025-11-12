#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a[100000][3];
	cin>>t;
	for(int i = 1;i<=t;i++){
		int n;
		cin>>n;
		int ax=0,ay=0,az=0,bx=0,by=0,bz=0;
		for(int j = 1 ; j<=n;j++){
			cin>>a[j][1];
			cin>>a[j][2];
			cin>>a[j][3];
			if(a[j][1]>a[j][2]){
				if(a[j][3]>a[j][1]){
					if(az<n/2){
						az++;
						bz+=a[j][3];
					}else if(ax<n/2){
						ax++;
						bx+=a[j][1];
					}else{
						ay++;
						by+=a[j][2];
					}
				}else if(a[j][3]<a[j][1]){
					if(az<n/2){
						az++;
						bz+=a[j][3];
					}else if(ax<n/2){
						ax++;
						bx+=a[j][1];
					}else{
						ay++;
						by+=a[j][2];
					}
				}else{
					if(az<n/2){
						az++;
						bz+=a[j][3];
					}else if(ax<n/2){
						ax++;
						bx+=a[j][1];
					}else{
						ay++;
						by+=a[j][2];
					}
				}
			}else{
				if(a[j][3]>a[j][2]){
					if(az<n/2){
						az++;
						bz+=a[j][3];
					}else if(ay<n/2){
						ay++;
						by+=a[j][2];
					}else{
						ax++;
						bx+=a[j][1];
					}
				}else if(a[j][3]<a[j][2]){
					if(ay<n/2){
						ay++;
						by+=a[j][2];
					}else if(az<n/2){
						az++;
						bz+=a[j][3];
					}else{
						ax++;
						bx+=a[j][1];
					}
				}else{
					if(az<n/2){
						az++;
						bz+=a[j][3];
					}else if(ax<n/2){
						ax++;
						bx+=a[j][1];
					}else{
						ay++;
						by+=a[j][2];
					}
				}
			}
			
		}
		cout<<bx+by+bz<<endl;
	}
	return 0;
}

