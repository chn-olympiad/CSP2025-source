#include<bits/stdc++.h>
using namespace std;
int jx[500],jy[500];
int n,m;
int a[500];
int cnt=1;
int ci;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	jx[1]=1;
	jy[1]=1;
	for(int i=2;i<=n*m;i++){
		if(jx[i-1]%2==1){
			if(jy[i-1]==n){
				jy[i]=jy[i-1];
				jx[i]=jx[i-1]+1;
				continue;
			}
			jx[i]=jx[i-1];
			jy[i]=jy[i-1]+1;
		}
		else{
			if(jy[i-1]==1){
				jy[i]=jy[i-1];
				jx[i]=jx[i-1]+1;
				continue;
			}
			jx[i]=jx[i-1];
			jy[i]=jy[i-1]-1;
		}
	}
	cin>>ci;
	for(int i=1;i<n*m;i++){
		int c;
		cin>>c;
		if(c>ci){
			cnt++;
		}
	}
	cout<<jx[cnt]<<" "<<jy[cnt];
	return 0;
}
