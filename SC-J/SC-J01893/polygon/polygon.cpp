#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int md;
				if(i>j){
					md=max(i,k);
				}
				else{
					md=max(j,k);
				}
				if((i+j+k)>md*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}