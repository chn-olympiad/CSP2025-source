#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
long long ans;
int main(){
	cin>>n>>k;
	int x,y=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==k){
			ans++;
		}
		else{
			a[++y]=x;
		}
	}
	for(int i=1;i<=y;i++){
		int l=a[i];
		for(int j=i;j<=y;j++){
			if(l&a[j]==k){
				l=a[j+1];
				ans++;
				break;
			}
		}
	}
	
	return 0;
} 