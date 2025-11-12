#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,j=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(j<n){
		if(k==0){
			if(a[j]==k){
				s++;
			}
			else if(j+1<n&&a[j]==a[j+1]){
				s++;
				j++;
			}j++;
		}if(k==1){
			if(a[j]==k){
				s++;
			}j++;
		}
	}cout<<s;
	return 0;
}
