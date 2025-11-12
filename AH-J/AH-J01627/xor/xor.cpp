#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int check(int x){
	int sum;
	int c=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i-2;j++)sum=a[i]^a[i+1];
	    for(int j=i;i<=n;i++){
		    if(sum==k){sum=0;c++;}
		    sum+=sum^a[j];
	    }
	}
	return c==x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1,r=n;
    while(l<r){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
    return 0;
}
