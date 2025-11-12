#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,k,all,i;
bool b[500005];
int main(){
		
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0){
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
	}else{
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				all++;
			}
		}
		cout<<all;
		return 0;
	}
	
	for( i=1;i<=n;i++){
		if(a[i]==k){
			all++;
			b[i]=1;
		}else if(a[i-1]^a[i]==k&&b[i-1]==0){
			all++;
			b[i]=1;
		} else{
			if(b[i-1]==0){
				a[i]=a[i-1]^a[i];
			}
		}
	}
	cout<<all;
	return 0;
} 
