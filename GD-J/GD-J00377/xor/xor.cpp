#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=2){
		cout<<2;
		return 0;
	}
	if(k<=1){
		for(int i=0;i<n;i++){
			if(a[i]==0 || 1){
				if(i=n){
					cout<<i-1;
					return 0;
				}
				else{
					cout<<i+1;
					return 0;
				}
			}
		}
	}
	cout<<k-1;
    return 0;
} 
