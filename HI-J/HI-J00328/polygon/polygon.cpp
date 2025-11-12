#include<bits/stdc++.h>
using namespace std;
int n,a[5005],amt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ii=0;
			int b[5005];
			for(int k=i;k<=j;k++){
				b[++ii]=a[k];
			}
			if(ii>=3){
				int maxn=-1,sumn=0;
				for(int k=1;k<=ii;k++){
					sumn+=b[k];
					maxn=max(maxn,b[k]);
				}
				if(sumn>maxn*2) amt++;
			}
			
		}
	}
	cout<<amt;
	return 0;
} 
