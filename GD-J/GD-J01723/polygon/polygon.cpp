#include<bits/stdc++.h>
using namespace std;
long long a[100000001],moo=998244353,ans=0,maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;i++){
			x+=a[j];
			maxn=max(a[j],maxn);
		}
		if(x>maxn*2){
			ans++;
			ans%=moo;
		}
	}
	cout<<ans%moo;
	return 0;
}
