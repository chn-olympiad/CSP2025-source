#include<bits/stdc++.h>
using namespace std;
long long n,k,b=1,o,z;
long long a[505050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1&&n==1)cout<<0;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				b=0;
				break;
			}
		}
		if(b==1)cout<<n/2;
		else{
			if(k){
				for(int i=1;i<=n;i++){
					if(a[i]==1)
						o++;
				}
				cout<<o;
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i]==0)
						z++;
					if(a[i]==1&&a[i+1]==1){
						z++;
						i++;
					}
				}
				cout<<z;
			}
		}
	}
	return 0;
}