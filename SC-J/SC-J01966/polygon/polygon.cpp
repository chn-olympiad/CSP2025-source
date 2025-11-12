#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("polygon.in","r","std.in");
	freopen("polygon.out","w","std.out");
	int n,z=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int h=0,mx;
		h+=a[i]+a[i+1];
		mx=max(a[i],a[i+1]);
		for(int j=i+2;j<n;j++){
			h+=a[j];
			mx=max(mx,a[j]);
			if(h>mx*2)z++;
		} 
	}
	cout<<z;
	return 0;
}