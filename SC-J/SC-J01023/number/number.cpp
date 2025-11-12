#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int main(){
	cin>>n;
	int i=1;
	while(1){
		if(n<10){
			a[i]=n;
			break;
		}
		a[i]=n%10;
		n/=10;
		i++;
	}
	for(int j=1;j<=i;j++){
		for(int k=j+1;k<=i;k++){
			if(a[k-1]<a[k]){
				swap(a[k-1],a[k]);
			}
		}
	}
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
    cout<<endl;
	return 0;
} 