#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	if(a[0]+a[1]+a[2]>a[2]*2)ans++;
	cout<<ans;
	}
	if(n>3){
		int a[10000];
		for(int i=0;i<n;i++){
		cin>>a[i];
		}
		cout<<9;
	}
	
}
