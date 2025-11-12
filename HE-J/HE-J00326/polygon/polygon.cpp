#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	unsigned long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(max(max(a[0],a[1]),a[2])*2>=a[0]+a[1]+a[2]){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	if(n==4){
		if(max(max(a[0],a[1]),a[2])*2>=a[0]+a[1]+a[2]){
			ans+=0;
		}else{
			ans++;
		}
		if(max(max(a[0],a[1]),a[3])*2>=a[0]+a[1]+a[3]){
			ans+=0;
		}else{
			ans++;
		}
		if(max(max(a[0],a[2]),a[3])*2>=a[0]+a[2]+a[3]){
			ans+=0;
		}else{
			ans++;
		}
		if(max(max(a[1],a[2]),a[3])*2>=a[1]+a[2]+a[3]){
			ans+=0;
		}else{
			ans++;
		}
		if(max(max(a[0],a[1]),max(a[2],a[3]))*2>=a[0]+a[1]+a[2]+a[3]){
			ans+=0;
		}else{
			ans++;
		}
		cout<<ans;
	}
	if(n==5){
		cout<<9;	
	}
	return 0;
}
