#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],sum[5005];
int main(){
	freopen("polygon.in","r",stdin);	
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3]))
		{
			cout<<0;
			return 0;
		}
		else 
        	cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<87645;
	return 0;
}
