#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],max_,i,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){ 
		cin>>a[i];
	}
	if(k==0){
		for(i=1;i<=n;i++){
			bool b=1;
			for(j=i;j<=n;j++){
				if(a[j]!=0){
					break;
				}
				max_=max(max_,j-i+1);
			}
		}
		cout<<max_;
	}
	if(k==1){
		for(i=1;i<=n;i++){
			if(a[i]==1)max_++;
		}
		cout<<max_;
	}
	return 0;
}
