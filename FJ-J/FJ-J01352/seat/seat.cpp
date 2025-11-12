#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[400];
int n,m;
int fng;
bool cmp(int a,int b){
	return a>b;
}
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+n*m+1,cmp);
	int jil=1;
	for(int i=1;i<=n;i++){
		if(fng%2==0){
			for(int j=1;j<=m;j++){
				if(b[jil]==r){
					cout<<i<<' '<<j;
					return 0;
				}
				a[j][i]=b[jil];
				++jil;
			}
		
		}else{
			for(int j=m;j>=1;j--){
				if(b[jil]==r){
					cout<<i<<' '<<j;
					return 0;
				}
				a[i][j]=b[jil];
				++jil;
			}
			
			}
		fng++;
	}
	return 0;
}
