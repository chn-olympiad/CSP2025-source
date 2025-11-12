#include<bits/stdc++.h>
using namespace std;
int n,k,ans,xor_sum,previous=1;
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int j=1;j<=n;++j){
		cin>>s[j];
		if(s[j]==k){
			xor_sum=0;
			ans++;
			previous=j+1;
		}
		else{
			xor_sum^=s[j];
			if(xor_sum==k){
				xor_sum=0;
				ans++;
				previous=j+1;
			}
			else{
				int b=xor_sum;
				for(int i=previous;i<j;++i){
					b^=s[i];
					if(b==k){
						xor_sum=0;
						ans++;
						previous=j+1;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
