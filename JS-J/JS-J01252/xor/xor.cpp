#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0,v=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int l=j;l<j+i;l++){
				v|=a[l];
			}
			if(v==k){
				s++;
				for(int l=j;l<j+i;l++){
					a[l]=INT_MAX;
				}
			}
			v=0;
		}
	}
	cout<<s;
    return 0;
}
