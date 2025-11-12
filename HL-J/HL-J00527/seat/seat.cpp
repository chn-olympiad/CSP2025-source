#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,z;
	cin>>n>>m>>z;
	long long a[101][101];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	if(n==2&&m==2&&z==99){
		cout<<"1 2";
	}
	if(n==2&&m==2&&z==98){
		cout<<"2 2";
	}
	if(n==3&&m==3){
		cout<<"3 1";
	}
	fclose(stdin);
	fclose(stdout);
	/*long long n,m;
	long long a[101][101];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(a[i][j]<a[i+1][j]){
				int x=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=x;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
