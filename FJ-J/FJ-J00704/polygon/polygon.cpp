#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001],ans=0,cnt=0;
	int max=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		if(i>=2){
			if(a[i]>max) max=a[i];
		}
		sort(a+i,a+i+1);
	}
	sort(a+n,a+n+1);	
	if(n==3){
		if(ans>max*2) cnt++;
	}else{
		if(ans>max*2) cnt++;	
	}
	cout<<cnt%998244353;
	return 0;
}
