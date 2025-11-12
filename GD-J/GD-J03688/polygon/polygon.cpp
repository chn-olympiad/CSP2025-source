#include<bits/stdc++.h>
using namespace std;
int a[6010];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		for(int j=i;j>=0;j--){
			for(int k=0;k<n;k++){
				
			}
		}
	}
	cout<<ans;
	return 0;
}
