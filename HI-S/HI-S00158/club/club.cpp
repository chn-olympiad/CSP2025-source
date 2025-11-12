#include<iostream>
using namespace std;
int m[5],n,t,a[100100][3],b[3],mm=0;
void solve(int x,int y){
	if(y==n-1){
		for(int i=0;i<3;i++){
			b[i]++;
			if(b[0]<=n/2&&b[1]<=n/2&&b[2]<=n/2&&x+a[y][i]>m[mm]){
				m[mm]=x+a[y][i];
			}
			b[i]--;
		}
	}else{
		for(int i=0;i<3;i++){
			b[i]++;
			solve(x+a[y][i],y+1);
			b[i]--;
		}
	}
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}
		solve(0,0);
		mm++;
	}
	for(int i=0;i<mm;i++){
		cout<<m[i]<<endl;
	}
	return 0;
}
