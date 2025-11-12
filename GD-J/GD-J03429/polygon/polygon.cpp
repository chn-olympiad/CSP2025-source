#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);	
	int n;
	int cnt=0;
	cin>>n;
	int a[n+5];
	if(n==3){
	
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		if(a[0]+a[1]>2*max(a[0],a[1])){
			cnt++;
		}
		if(a[1]+a[2]>2*max(a[1],a[2])){
			cnt++;
		}
		if(a[1]+a[2]+a[0]>2*a[2]){
			cnt++;
		}
		if(a[0]+a[2]>2*a[2]){
			cnt++;
		}
		cout<<cnt;
	}
	else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<0;
	}
	return 0;
}
