#include<bits/stdc++.h>
using namespace std;
int n;
int a[50010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1<<"\n";
			return 0;
		}
	}
	cout<<0<<"\n"; 
	return 0;
} 
