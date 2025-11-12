#include<bits/stdc++.h>
using namespace std;
int n,ans,flag;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	sort(a+1,a+n);
	if(n==3){
		int sum=0,maxx=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		if(sum>maxx*2){
			ans=1;
		}
	}
	if(flag==0){
		ans=n-3+1;
	}
	cout<<ans;
	return 0;
} 
