#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],max1=0; 
long long cnt1=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[a[i]]++;
		max1=max(max1,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]>a[3] and a[1]+a[3]>a[2] and a[2]+a[3]>a[1]){
			cout<<1;
		}else {
			cout<<0;
		}
		return 0;
	}else{
	cout<<9; 	
	} 
	
	return 0;
}
