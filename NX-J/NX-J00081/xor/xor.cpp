#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
int a[n];
int aa;
int c=0;
int ans=0;
for(int i=0;i<n;i++){
	cin>>aa;
	if(i==0)continue;
	a[i]=a[i-1]^aa;
}
for(int i=0;i<n;i++){
	for(int j=i;j<n;j++){
		c=a[i]^a[j];
		if(c==k){
			ans++;
			for(int ii=j-i;ii<n;ii++){
				a[ii]^=k;
			}
		}
	}
}
cout<<ans;
return 0;
}
