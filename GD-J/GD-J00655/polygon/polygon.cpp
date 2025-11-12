#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} 
