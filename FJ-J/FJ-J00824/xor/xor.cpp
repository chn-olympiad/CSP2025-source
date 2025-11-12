#include<bits/stdc++.h>
using namespace std;
int r[500000];
int main(){
	freopen("xor.in","in",stdin);
	freopen("xor.out","out",stdout);
	int n,k;
	cin>>n>>k;
	int l=0;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	for(int i=0;i<n;i++){
		int p=r[i];
		int j=i;
		while(j!=n-1){
			if(r[i]==k){
				l=l+1;
				break;
			}
			j++;
			if(p%2!=r[j]%2){
				p=p+r[j];
			}else{
				p=abs(p-r[j]);
			}
			if(p==k){
				l=l+1;
				i=j;
				break;
			}
		}
	}
	cout<<l;
	return 0;
}
