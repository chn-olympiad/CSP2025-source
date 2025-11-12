#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m,i,j,h,l,z,ds;
	cin>>n>>m;
	int a[n][m],k[m*n],wz=0;
	for(i=0;i<m*n;i++){
		cin>>k[i];
	}z=k[0];
	sort(k,k+m*n);
	int tc=0;
	for(i=m-1;i>=0;i--){
		if(i%2==1){
			for(j=0;j<n;j++){
				a[j][i]=k[wz];
				if(k[wz]==z){
					cout<<i+1<<" "<<j+1;
					tc=1;break;
				}wz++;
			}
		}else{
			for(j=n-1;j>=0;j--){
				a[j][i]=k[wz];
				if(k[wz]==z){
					cout<<i+1<<" "<<j+1;
					tc=1;break;
				}wz++;
			}
		}
		if(tc==1){
			break;
		}
	}
	return 0;
}
