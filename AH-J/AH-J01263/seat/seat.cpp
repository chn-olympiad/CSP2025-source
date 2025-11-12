#include <bits/stdc++.h>

using namespace std;
int a[105];
int b[15][15];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,bj,pt,a1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m);
	pt=n*m-1;
	for(int i=0;i<m;i++){
		bj=i%2;
		if(bj==0){
			for(int j=0;j<n;j++,pt--){
				b[i][j]=a[pt];
				if(b[i][j]==a1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--,pt--){
				b[i][j]=a[pt];
				if(b[i][j]==a1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
			
			
		}
	}
	
	return 0;
}
