#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,l=1,r=1,sum,ans;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    while(l<=n&&r<=n){
		sum=0;
		for(int i=l;i<=r;i++){
		    if(l==r)sum=a[l];
			if(i==l) sum+=a[i] xor a[i+1];
			else sum+=sum xor a[i+1];
		 }
		 if(sum==k){
			 ans++;
			 l=r++;
		 }
		 else if(sum!=k){
			 r++;
		 }
	}
	cout<<ans;
    return 0;
}
