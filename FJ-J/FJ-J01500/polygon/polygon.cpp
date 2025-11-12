#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[55]={0},sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int g=3;g<=n;g++){
		for(int i=1;i<=n-g+1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					int x=a[i]+a[j]+a[k],y=2*a[k];
					if(x>y) sum++; 
				}
			}
		}
	}
	cout<<sum; 
	return 0;
} 

