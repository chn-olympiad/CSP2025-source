#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int b[15][15];
int i,j,k;
int a1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(i=0;i<m*n;i++){
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+m*n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i%2==0){
				b[j][i]=a[k];
			}
			else{
				b[m-j-1][i]=a[k];
//				cout<<a[k]<<endl;
			}
			if(b[j][i]==a1){
				cout<<i+1<<" "<<j+1<<endl;
				return 0;
			}
			k++;
		}
	}
//	for(i=0;i<m;i++){
//		for(j=0;j<n;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}

