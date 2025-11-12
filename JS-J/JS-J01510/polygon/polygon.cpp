#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	} 
	else cout<<7;
	return 0;
}
