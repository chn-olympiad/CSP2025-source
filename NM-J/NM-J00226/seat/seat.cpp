#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,r,z;
	cin>>n>>m;
	bool k=true;//true为自上至下 
	int a[n*m]={},b[n][m]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	z=n*m-1;
	sort(a,a+n*m);
	for(int i=0;;){
		for(int j=0;;){
			b[i][j]=a[z];
			if(a[z]==r){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
			z--;
			if(k){
				if(i==n-1){
					j++;
					k=false;
				}else{
					i++;
				}
			}else{
				if(i==0){
					j++;
					k=true;
				}else{
					i--;
				}
			}
		}
	}
	return 0;
}
