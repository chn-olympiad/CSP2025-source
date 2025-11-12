#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(max(a[2],max(a[1],a[0]))<a[1]+a[2]+a[0]-max(a[2],max(a[1],a[0]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}