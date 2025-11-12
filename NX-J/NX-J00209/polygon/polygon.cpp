#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int arr[n+10];
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	int m=0;
	for(int i=0;i<=n;i++){
        int x=0;
        int lei=0;
        for(int j=n;j>=i;j--){
            for(int k=i;k<=j;k++){
                x+=arr[i];
                if(lei<arr[i]){
                    lei=arr[i];
                }
            }
        }
        if(lei*2<x){
            m++;
        }

	}
	m+=1;
	cout<<m;
	return 0;
}

