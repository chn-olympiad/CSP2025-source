#include<bits/stdc++.h>
using namespace std;
int a[5000],b[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(n<=3){
		if(a[0]+a[1]>a[2])
		cout<<1;
		else
		cout<<0;
		return 0;
	}if(n==4){
		int ans=0;
		if(a[0]+a[1]>a[2]){
			ans++;
		}if(a[0]+a[1]>a[3])ans++;
		if(a[1]+a[2]>a[3]){
			ans++;
		}if(a[1]+a[2]+a[0]>a[3])
			ans++;
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}
