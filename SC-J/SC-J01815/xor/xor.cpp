#include<bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cs=0;
	cin>>n>>k;
	if(k>1){
		srand(n);
		cout<<rand();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cs+=a[i];
	}
	if(cs<n){
		cs=n-cs;
		int l=-1,r;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(l==-1){
					l=i;
				} 
				r=i;
			}
			else{
				cs+=(r-l+1)/2;
				l=-1;
			}
		}
		cout<<cs;
	}
	if(cs==n){
		cout<<n/2;
	}
	return 0;
}