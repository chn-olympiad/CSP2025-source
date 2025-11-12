#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	int a[5001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int num;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]>a[k]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 
