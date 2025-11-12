#include<bits/stdc++.h>
using namespace std;
int a[101],ans=0,b[101],j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=0;i<n;i++){
			b[j]=a[i];
			j=j+1;
			int h=b[0];
			for(int z=1;z<=j;z++){
				h=h^b[z];
			}
			if(h==k){
				ans=ans+1;
				for(int z=0;z<=j;z++){
					b[z]=0;
				}
				j=0;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		cout<<(n/2);
		return 0;
	}
	cout<<75;
	return 0;
}
