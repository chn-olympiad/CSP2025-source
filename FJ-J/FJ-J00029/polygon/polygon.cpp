#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool check(){
	if(a[1]+a[2]<=a[3]){
		return false;
	}
	return true;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	sort(a+1,a+n+1);
	if(n==3&&check()){
		cout<<1;
		return 0;
	}else if(n==3&&check()==false){
		cout<<0;
		return 0;
	}
	return 0;
}
