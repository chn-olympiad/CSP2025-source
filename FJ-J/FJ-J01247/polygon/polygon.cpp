#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
bool vis[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i!=j&&j!=k&&a[i]+a[j]+a[k]>a[k]*2){
					sum++;
				}
			}
		}
	}*/
	if(a[1]+a[2]+a[3]>a[3]*2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	
	
	
	
	
	return 0;
}
