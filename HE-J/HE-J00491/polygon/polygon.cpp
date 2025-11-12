#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int sum;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>a[i];
	}
	ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;++i){
		for(int j=1;j<=n-i;++j){
			for(int k=i;k<=i+j;++k){
				sum+=a[j];
			}
			if(sum>(a[i+j]*2)){
				ans++;
			}
		}
		
	}
	cout<<ans;
    return 0;
}
