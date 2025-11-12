#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,ans=0,i,s=0,j,d=0,x=0;
inline void renew(){
	ans++;
	while(s<=i)d^=a[s],s++;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++,x=0){
		d^=a[i];
		if(d==k)renew();
		for(j=s;j<i;j++){
			x^=a[j];
			if((d^x)==k){
				renew();break;
			}
		}
	}
	cout<<ans;
}
