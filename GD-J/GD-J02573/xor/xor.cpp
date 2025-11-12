#include<bits/stdc++.h>
using namespace std;
int n,k,a[500011],b[500011],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			for(int o=i;o<=j;o++){
				if(b[o]){
					b[o]=o;
					b[i]=o;
				}else b[o]=1;
			}
			if(b[i]!=1){
				for(int o=i;o<=j;o++){
					if(b[o]>1){
						b[o]=1;
					}else b[o]=0;
				}
				break;
			}
			int sum=0;
			for(int p=i;p<=j;p++) sum=sum^p;
			if(sum==k) ans++;
			for(int o=i;o<=j;o++){
				if(b[o]>1){
					b[o]=1;
				}else b[o]=0;
			}
		}
	cout<<ans;
	return 0;
}
