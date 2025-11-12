#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100],vis[100];
bool j(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a,a+k,j);
	for(int i=1;i<=k;i++){
		if(i%n==1 && (i/n)%2==1){
			for(int j=i;j<=i+n-1;j++){
				vis[i]=a[i+n-1-j%n];
			}
		}
		else{
			vis[i]=a[i]; 
		} 
	}
	for(int i=1;i<=k;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}
