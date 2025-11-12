#include<bits/stdc++.h>
using namespace std;
long long n,k; 
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==0){
			if(a[i]==k){
				cout<<1;
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
