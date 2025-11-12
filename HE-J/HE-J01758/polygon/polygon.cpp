#include<bits/stdc++.h>
using namespace std;
int n,z=0;
int a[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)cout<<0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>2*a[k]){
				    z=z+1;	
				}
			}
		}
	}	
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
