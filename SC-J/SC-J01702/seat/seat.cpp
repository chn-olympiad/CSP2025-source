#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[15][15];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c,r;
	int R=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i+1;j++){
			int d=a[j],x=a[j+1];
			a[j]=max(x,d);
			a[j+1]=min(x,d);
		}
	}
	
	int q=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[q];
				if(b[j][i]==R){
					c=i;
					r=j;
				}
				q++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[q];
				if(b[j][i]==R){
					c=i;
					r=j;
				}
				q++;
			}
		}
	}
	cout<<c<<" "<<r;
}