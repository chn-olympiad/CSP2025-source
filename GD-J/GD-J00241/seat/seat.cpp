#include <bits/stdc++.h>
using namespace std;
int a[100001];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=n*m-i+1;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			    sum++;
			    if(sum==k) {
			    	cout<<i<<" "<<j; 
			    	return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
			    sum++;
			    if(sum==k) {
			    	cout<<i<<" "<<j; 
			    	return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
