#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],c,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=a[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				if(i>l){
					c++;
					l=j;
					break;
				}
			}
		}
	}
	cout<<c;
}  
