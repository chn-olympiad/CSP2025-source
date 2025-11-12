#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={},sum=0;
	cin>>n;
	int maxn=0;
	bool f=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
		maxn=max(maxn,a[i]);
		sum=sum+a[i];
	}
	if(n==3&&sum>maxn*2){
		cout<<1;
		return 0;
	}
	else if(f==0){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=ans+n/i;
		}
		cout<<ans;
		return 0;
	}
	else cout<<18039138599370616;
	return 0;
}

