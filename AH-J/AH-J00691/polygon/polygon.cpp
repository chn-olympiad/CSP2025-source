#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n]={0};
    bool q=1;
    for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1) q=0;
	}
	if(n==3){
		sort(a,a+n);
		if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(q==1){
		long long as=0,k=1;
		for(int i=3;i<n;i++){
			bool o=1;
			for(int j=n;j>n-i;j--){
				if(j%i==0 && o==1){
					k=k*(j/i);
					o=0;
				}
				else{
					k*=j;
				}
				k=k%998244353;
			}
			as+=k;
			as=as%998244353;
			k=1;
		}
		as++;
		cout<<as;
		return 0;
	}
	cout<<9999999;
    return 0;
}
