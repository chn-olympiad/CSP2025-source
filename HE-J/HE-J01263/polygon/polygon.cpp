#include<iostream>
using namespace std;
int maxn3(int a,int b,int c){
	if(a>=b&&a>=c){
		return a;
	}
	if(b>=a&&b>=c){
		return b;
	}
	if(c>=a&&c>=b){
		return c;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int l=j+1;l<n;l++){
				if(maxn3(a[i],a[j],a[l])*2>(a[i]+a[j]+a[l])){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
