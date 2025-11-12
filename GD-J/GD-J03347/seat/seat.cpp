#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int c,d;
	cin>>c>>d;
	int e;
	for(int i=1;i<=c*d;i++){
		cin>>b[i];
	}
	e=b[1];
	for(int i=1;i<=c*d;i++){
		for(int j=1;j<=i;j++){
			if(b[i]>b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=d;j++){
			if(i%2==1){
				a[j][i]=b[j+c*(i-1)];
			}
			else if(i%2==0){
				a[j][i]=b[c*i-(j-1)];
			}
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=d;j++){
			if(a[i][j]==e){
				cout<<j<<' '<<i;
			}
		}
	}
}
