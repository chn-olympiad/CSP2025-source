#include<iostream>
using namespace std;
int n,k,a[500005],mx,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx); 
	}
	if(mx<=1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else{
					int d=0;
					while(a[i]==1){
						i++;
						d++;
					}
					i--;
					sum+=d/2;
				} 
			}
			cout<<sum;
		}
		return 0;
	}
	return 0;
} 
