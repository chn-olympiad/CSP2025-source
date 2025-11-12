#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	char n;
	while(cin>>n){
		if('0'<=n && '9'>=n){
			a[n-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}
	return 0;
} 
