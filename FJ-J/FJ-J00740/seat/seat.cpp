#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int a[maxn];
	int m,n,b[11][11],r;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
			a[i*n+j]=b[i][j];
		}
	}
	r=b[0][0];
	sort(a,a+n*m,cmp);
	int f=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				b[j][i]=a[f];
				f++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				b[j][i]=a[f];
				f++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==r){
			 	cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
}
