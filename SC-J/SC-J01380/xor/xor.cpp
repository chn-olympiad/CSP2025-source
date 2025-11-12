#include<bits/stdc++.h>
using namespace std;
int n,a[200010],k,g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				g++;
			}
		}
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				g++;
			}else if(a[i]==1){
				int j=i+1;
				while(a[j]!=1){
					j++;
				}
				i=j;
				g++;
			}
			
		}
	}
	cout<<g;
	return 0;
}