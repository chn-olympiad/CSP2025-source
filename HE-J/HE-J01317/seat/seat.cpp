#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[101];
	int q,i;
	while(i<=n*m){
		cin>>a[i];
		i++;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(a[j]<a[j-1]){
					a[j]=q;
					q=a[j-1];
					a[j-1]=a[j];
				}
			}
		}
		cout<<a; 
	}
	return 0;
}
