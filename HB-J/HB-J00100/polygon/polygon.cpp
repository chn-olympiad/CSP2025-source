#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt,n,k,c=0,a[50000086];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	k=max(k,a[i]);
}
if(n<=2){
	cout<<0;
	return 0;
}
for(int r=1;r<=n;r++){
	for(int l=1;l<=r;l++){
		for(int i=l;i<=r;i++)c+=a[i];
		if(c>k*2&&(r-l)>=2){
			cnt++;
			//cout<<l<<" "<<r<<endl;
			}
		c=0;
	}
}
cout<<cnt%998244353;
return 0;
}
