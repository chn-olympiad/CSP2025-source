#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[N][4]; 
	cin>>t;
	int sum=0;
	while(t!=0){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				max((a[i][j],a[i][j+1]),a[i][j+2]);
				sum+=a[i][j];
				a[i+1][j]=a[i][j];
				a[i+1][j+1]=a[i][j+1];
				a[i+1][j+2]=a[i][j+2];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
