#include<bits/stdc++.h>
using namespace std;
int n,s[5005],m=0,l=1,r=3,ans=0;
bool p(int a,int b){
	int t[5005],tp=0,z=0;
	for (int i=a;i<=r;i++){
		t[z]=s[i];
		tp+=s[i];
		z++;
	}
	sort(t,t+z);
	if(tp>2*t[z-1]){
		return 1;
	}
	return 0;
}
bool c(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,c);
	for (l=0;l<n-2;l++){
		for(r=2;r<n;r++){
			if(p(l,r)){
			ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
