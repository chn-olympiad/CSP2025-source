#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,r,ansn,ansm;
	bool f=false;
	cin>>n>>m;
	int a[m][n],b[m*n];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		r=b[0];
	}
	sort(b,b+n*m);
	for(int i=m-1;i>=0;i--){
		if((n-1)%2==0){
			for(int j=0;j<n;j++){
				if(b[cnt]==r){
					ansn=j;
					ansm=i;
					f=true;
					break;
				}
				a[i][j]=b[cnt++];
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(b[cnt]==r){
					ansn=j;
					ansm=i;
					f=true;
					break;
				}
				a[i][j]=b[cnt++];
			}
		}
		if(f){
			break;
		}
	}
	cout<<m<<n;
	return 0;
} 
