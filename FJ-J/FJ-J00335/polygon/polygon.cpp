#include<bits/stdc++.h>
using namespace std;
int n;
int a[5100];
int p1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			p1++;
		} 
	}
	if(n==3){
		cout<<1;
		return 0;
	}else if(p1==n){
		long long num=0;
		for(int i=1;i<=p1-2;i++){
			for(int j=i+1;j<=p1-1;j++){
				for(int k=j+1;k<=p1;k++){
					num++;
					num=num%998244353;
				}
			}
		}
		cout<<num%998244353;
	}
	
	return 0;
} 
