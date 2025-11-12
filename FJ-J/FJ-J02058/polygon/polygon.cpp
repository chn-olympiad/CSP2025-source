#include<iostream>
using namespace std;
int n,s;
int a[1001],b[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=4;i<=n;i++){
		for(int j=i;j<=n;j++){
			s = s+n-i+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i]+a[j]>a[l]&&a[i]+a[l]>a[j]&&a[j]+a[l]>a[i]){
					s++;
				}
			}
		}
	}
	cout<<s;
	return 0;
}