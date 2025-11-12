#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=i;l<=j;l++){
				
				if(l==i){
					ans=a[l];
					
				}else{
					ans^=a[l];
					
				}
				if(ans==k){
					cnt++;
					i=j+1;
					
					break;
				}	
			}
		}
	}
	cout<<cnt;
	return 0;
} 
