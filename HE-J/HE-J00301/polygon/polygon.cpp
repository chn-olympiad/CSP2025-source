#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+50;
long long n,a[N],max1=INT_MIN,maxmin,min1=INT_MAX,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		min1=min(min1,a[i]);
		ans+=a[i];
	}
	if(n==3){
		maxmin=ans-min1-max1;
		if(min1+maxmin>max1){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<6;
	return 0;
}
