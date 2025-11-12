#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,a[100],b=0,f,k;
	cin>>f;
	a[0] = f;
	for(int i = 1;i<m*n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i = 0;i<m*n;i++){
		if(a[i] == f){
			k = i;
		}
	}
	for(int i = 1;i<=m;i++){
		if(i%2 == 0){
			for(int j = n;j>=1;j++){
				if(b==k){
					cout<<i<<' '<<j;
					return 0;
				}
				b++;
			}
		}
	}
}
