#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int a[30][30],b[130]; 
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int sdf=b[1];
	sort(b+1,b+1+m*n,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[(i-1)*n+j];
			}
		}else{
			int c[110];
			for(int j=n;j>=1;j--){
				c[j]=b[(i-1)*n+j];
			} 
			sort(c+1,c+1+n);
			for(int j=1;j<=n;j++){
				a[j][i]=c[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sdf){
				cout<<j<<" "<<i; 
				break;
			}
		}
	}
	return 0;
} 
