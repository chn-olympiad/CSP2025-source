#include<bits/stdc++.h>
using namespace std;
int a[110],c[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int b[m][n]; 
	bool pan[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c[i]=a[i];
		pan[i]=false;
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n*m;i++){
		a[i]=c[n*m-(i-1)];
	}

	for(int s=1;s<=m;s++){
		if(s%2!=0){
			int k=(s-1)*n+1;
			for(int j=1;j<=n;j++){
				if(pan[k]==false){
					b[s][j]=a[k];
					pan[k]=true;
				}
				if(b[s][j]==r){
					cout<<s<<" "<<j;
					return 0;
				}
				k++;
			}
		}
		if(s%2==0){
			int k=(s-1)*n+1;
			for(int j=n;j>=1;j--){
				if(pan[k]==false){
					b[s][j]=a[k];
					pan[k]=true;
				}
				if(b[s][j]==r){
					cout<<s<<" "<<j;
					return 0;
				}
				k++;
			}
		}	
	}
	return 0;
} 
