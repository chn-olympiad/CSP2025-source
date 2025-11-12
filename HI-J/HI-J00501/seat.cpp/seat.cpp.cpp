#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long a[15][15],b[105],c[105];
long long n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=0,l=0;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];	
		c[i]=b[i];
	} 
	sort(b+1,b+(n*m)+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[i][j]=b[k];
				k++;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j]=b[k];
				k++;
			}
		}	
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i][j]==c[1]){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
