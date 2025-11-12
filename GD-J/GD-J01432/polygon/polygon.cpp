#include<bits/stdc++.h>
using namespace std;
using lo=long long;
const lo N=998244353;
lo n;
lo a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ane=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			lo l=1,r=n;
			while(l<=r){
				lo mid=(l+r)/2;
				if(mid<a[j]+a[i])l=mid+1;
				else if(mid>a[i]+a[j])r=mid-1;
				else if(mid==a[i]+a[j])r=mid-1;
			}
			//l-1
			for(int k=1;i<=l-1;k++){
				if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j])ane++;
			}
		}
	}
	cout<<ane%N;
	return 0;
}
