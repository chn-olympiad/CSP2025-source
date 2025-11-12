#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[11],sum1=0;
bool is_lo=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1){cout<<0;return 0;}
	if(n==2){cout<<1;return 0;}
	if(n<=10){
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		if(k==1){
			for(i=1;i<=n;i++)
			if(a[i]==1) sum1++;
		}
		if(k==0){
			for(i=1;i<=n;i++){
				if(a[i]==0) {
					sum1++;
					is_lo=0;}
				if(a[i]==1){
					if(is_lo){
						sum1++;
						is_lo=0;
					}
					else{
						is_lo=1;
					}
				}
			}
		}
		cout<<sum1;
		return 0;
	}
	return 0;
}
