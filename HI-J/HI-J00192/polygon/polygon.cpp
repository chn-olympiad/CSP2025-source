#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	int a;
	for (int j=0;j<n;j++){
		if(arr[j+1]>arr[j]){
			a=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=a;
		}
	}
	int b=0;
	int c=0;
	for(int k=3;k<n;k++){
		for(int l=0;l<n;l++){
			for(int m=l+1;m<n;m++){
				if(k>=3){
					for(int z=m+1;z<n;z++){
						b=arr[l]+arr[m]+arr[z];
						if(k>=4){
							for(int y=m+1;y<n;y++){
								b+=arr[y];
								if(k==5){
									for(int x=m+1;x<n;x++){
										b+=arr[x];
									}
								}
							}
						}
					}	
				}
				if (b>arr[n]){
					c++;
				}
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
