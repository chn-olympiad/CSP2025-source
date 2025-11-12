#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0,l,r,b,c[500005]={0};

int  main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	
	cin>>n>>k;

	for (int i=1;i<=n;i++){
		cin>>a[i];
	
		if (a[i]==k){
			ans++;
			c[i]++;}
	}
	for (int i=1;i<=n;i++){
		l=i;
		r=n;
	while (l!=r){
		
		
		b=a[l]^a[r];
		for (int j=l+1;j<=r-1;j++) {
			b^=a[j];
		}
		if (b==k){
		for (int o=l;o<=r;o++) {
			c[o]++;
		}
			
			ans++;
			}
			r--;
	
}
}
	sort (c+1,c+n+1);
	cout<<ans-c[n];
	

	return 0;
}
