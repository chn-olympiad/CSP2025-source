#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v[72][72],i=1,j,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				v[i][j]=a[k];k++;
			}
				
		}
			
	}
	for(int k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				if(v[i][j]==0){
					v[i][j]=n;
				}
			}
				
		}
			
	}
	for(int x=n/2+1;x>=1;x--){
		for(int y=1;y<=x;y++){
			v[x][y]+=v[x-1][y]+v[x-1][y+1];
		}
			
	}
	cout<<v[1][1];
	return 0;
}
