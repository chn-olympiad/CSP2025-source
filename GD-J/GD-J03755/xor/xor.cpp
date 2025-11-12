#include <bits/stdc++.h>
using namespace std;
int n,k,c,sum,a[500010];
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(c==1){
					c=0;
				} 
				sum++;
			}else if(c==1){
				sum++;
				c=0;
			}else{
				c++;
			}
		}
		cout<<sum;
	}
	return 0;
}
