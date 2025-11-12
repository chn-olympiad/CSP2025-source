#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5000];
    int sum=0,max=-1;
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>max){
		max=a[i];
	}
		if(n>=3){
			if(a[i*n]>max*2){
				sum=sum+i;
			}
			}
	}
	cout<<sum;
    return 0;
}
