#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,m,a[100005],b[100005],t,k,ans,wq,wr;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout)£»
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[1]>a[2]>a[3]&&n%2<=a[i]){
				ans+=a[1];
			}
			else if(a[2]>a[1]>a[3]&&n%2<=a[i]){
				ans+=a[2];
			}
			else{
				ans+=a[3];
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[1]>a[2]>a[3]&&n%2<=a[i]){
				wq+=a[1];
				 
			}
			else if(a[2]>a[1]>a[3]&&n%2<=a[i]){
				wq+=a[2];
			}
			else{
				wq+=a[3];
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[1]>a[2]>a[3]&&n%2<=a[i]){
				wr+=a[1];
				 
			}
			else if(a[2]>a[1]>a[3]&&n%2<=a[i]){
				wr+=a[2];
			}
			else{
				wr+=a[3];
			}
	}
	cout<<ans<<endl<<wq<<endl<<wr;
	}

}
