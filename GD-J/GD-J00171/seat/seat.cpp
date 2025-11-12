#include<bits/stdc++.h>
//code by twly
//keda is DarSharBee! 
using namespace std;
int a[100][100];
int z[1000];
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	z[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>z[i];
	}
	sort(z+1,z+1+n*m);
	int cnt=n*m;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				
				a[i][j]=z[cnt];
				if(z[cnt]==r){
					cout<<i<<' '<<j;
					return 0; 
				}
				cnt--;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=z[cnt];
				if(z[cnt]==r){
					cout<<i<<' '<<j;
					return 0; 
				}
				cnt--;
			}
		}
	}
	
	return 0;
}
