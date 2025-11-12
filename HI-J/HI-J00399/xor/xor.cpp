#include<bits/stdc++.h>
using namespace std;
int a[100005],k,n,l,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int max=1;
		if(a[l]<=a[r]){
			max++;
			if(n>max){
				n=max;
			}
		}	
	}
	cout<<n;
	return 0;
}

