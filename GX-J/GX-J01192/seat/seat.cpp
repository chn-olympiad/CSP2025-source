#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)cin>>a[i];
	int w=a[0];
	sort(a,a+n*m);
	int z=0;
	for(int i=m;i>0;i--){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				if(a[z]==w)cout<<i<<" "<<j;
				z++;
			}
		}else{
			for(int j=n;j>0;j--){
				if(a[z]==w)cout<<i<<" "<<j;
				z++;
			}
		}
	}
	return 0;
}
