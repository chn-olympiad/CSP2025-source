#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=114;

int a[N][N];
int b[N*N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	
	int n,m;
	cin>>n>>m;
	int st;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	st=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				//a[j][i]=b[(i-1)*n+j]; 
				if(b[(i-1)*n+j]==st){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}	
		}
		else {
			for(int j=n;j>=1;j--){
				//a[j][i]=b[i*n-j+1];
				if(b[i*n-j+1]==st){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	 
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	return 0;
} 
