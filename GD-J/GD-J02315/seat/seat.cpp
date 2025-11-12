#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[1001][1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int x=a[1];
	sort(a+1,a+1+(n*m) );
	for(int i=1,j=n*m;i<j;i++,j--){
		swap(a[i],a[j]);
	} 
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int l=1;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				b[i][j]=a[l];
//				cout<<i<<' '<<j<<" "<<b[i][j]<<endl;
				l++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				b[i][j]=a[l];
//				cout<<i<<' '<<j<<" "<<b[i][j]<<endl;
				l++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
} 

