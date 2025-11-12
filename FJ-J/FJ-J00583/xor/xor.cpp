#include <bits/stdc++.h>
using namespace std;
int a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int b=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				b++;
			}
		}
		cout<<b;
	}else{
		int b=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			}
		}
		cout<<b;
	}
	return 0;
} 

