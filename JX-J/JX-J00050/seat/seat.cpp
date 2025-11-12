#include<bits/stdc++.h>
using namespace std;
int b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int c=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[l]!=c){b[j][i]=a[l]; l++;}
				else{cout<<j<<" "<<i; return 0;}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[l]!=c){b[j][i]=a[l]; l++;}
				else{cout<<j<<" "<<i; return 0;}
			}
		}
	}
	return 0;
}
