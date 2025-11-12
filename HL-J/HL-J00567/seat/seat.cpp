#include <bits/stdc++.h>
using namespace std;
int a[105];
int z[15][15];
int sum(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,s;
	cin>>n>>m;
	for(int j=1;j<=m;j++){
		cin>>a[j];
		s=a[1];	
		sort(a+1,a+m*n+1,sum);
		for(int i=1;i<=n;i++){
			z[x][i]=a[j];
			if(s==z[x][i] and x<=m and i<=n){
				if(s==z[x][i] and z[x][i]==s and s!=a[j]){
					cout<<x<<" "<<i<<endl;
				}	
			}
			if(i==n){
				if(x>m){
					break;
				}
				x++;
			for(int i=n;i>=1;i--){
				z[x][i]=a[j];
				j++;
				if(s==z[x][i] ){
					cout<<x<<" "<<i<<endl;
				}
				if(i==1){
					if(x>m){
						break;
					}
					x++;
					break;
				}
				if(x>m){
					break;
				}
			}	
			}
			if(x>m){
				break;
			}
		}
	}		
}







