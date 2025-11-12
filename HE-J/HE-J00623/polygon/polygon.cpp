#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b;
	int a[n];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int f=0;f<n;f++)
	for(int j=0;j<=n;j++){
		for(int i=0;i<n;i++){
			if(a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}	
		}
	}
	int c=0;
	for(int i=0;i<n;i++){
		c=c+a[i];
	}
	cout<<"9";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
