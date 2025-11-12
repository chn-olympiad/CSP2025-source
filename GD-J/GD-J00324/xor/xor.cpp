#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,s=0,a[500010],b[500010],c[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m>>a[1];
	b[1]=a[1];
	l=n;
	r=n+1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	while(l--){
		for(int i=l;i<=n;i++){
			if(i>=r){
				break;
			}
			if((b[i]^b[l-1])==m){
				r=l;
				s+=1;
				c[l]=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
