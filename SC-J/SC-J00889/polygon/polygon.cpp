#include<iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int z=0;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int q=a[j];
				a[j]=a[i];
				a[i]=q;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int s=1;
			int p=a[i]+a[j];
			for(int k=j+1;k<n;k++){
				if(p>a[k]){
					z=z+s;
					s++;
				}
				else p=p+a[j+1];
			}
		}
	}
	cout<<z;
    return 0;
}