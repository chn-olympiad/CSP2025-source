#include<bits/stdc++.h>
using namespace std;
int a[101];int b[10][10];
bool oo(int c,int d){
	if(c<d)return 0;
	else return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	l=a[0];
	sort(a,a+m*n,oo);
	int p=0;
	for(int i=0;i<m;i++){
		if((i+1)%2==0){
			for(int j=n-1;j>=0;j--){
				b[i][j]=a[p++];
			}	
		
		}
		else{
			for(int j=0;j<n;j++){
				b[i][j]=a[p++];
			}
		}
	
	}int o=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==l){
				cout<<i+1<<" "<<j+1;
				o=1;
				break;
			}
		}
		if(o==1)break;
	}
	return 0;
}
