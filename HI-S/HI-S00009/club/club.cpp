#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N][3];
int t,n,r;
int ax,bx,cx;
int axz,bxz,cxz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		r=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				if(axz<=r){
					ax+=a[i][0];
					axz++; 
				}
			}
			if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
				if(bxz<=r){
					bx+=a[i][1];
					bxz++; 
				}
			}
			if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]){
				if(cxz<=r){
					cx+=a[i][2];
					cxz++; 
				}
			}
		}
		cout<<ax+bx+cx<<endl;
		ax=0;
		bx=0;
		cx=0;
		axz=0;
		bxz=0;
		cxz=0;
	}
	
	return 0;
}

