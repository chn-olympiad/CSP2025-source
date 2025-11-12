#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500100];
int ans=0;
int bj=1;
;int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int r=1;r<=n;r++){
	for(int l=bj;l<=r && l>=bj;l++){
		int sum=a[l];
		for(int m=l;m<=r;){
			if(sum==k){
				ans++;
				bj=m+1;
				//cout<<l<<" " <<r<<" "<<bj<<endl;
				break;
			}
			m++;
			sum=sum^a[m];
		}
	}
}
cout<<ans;
return 0;
}
