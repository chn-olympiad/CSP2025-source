#include <bits/stdc++.h>
using namespace std;
int n,r;
int a[100005];
int aaa(int z,int t){
	int b,v,c=0;
		c+=a[z];
		if (a[z-1]==a[1]){
			if (a[0]+c>2*a[t]){
				return 1;
				}}
				v+=aaa(z-1,t);}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>a[i];}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		r+=aaa(i,i);
	cout<<r;
}
	return 0;}
