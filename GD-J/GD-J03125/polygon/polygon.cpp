#include<bits/stdc++.h>
using namespace std;
int n;
int a[6005];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}
		else{
			int mx=0,sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
				mx=max(mx,a[i]);
			}
			if(sum>2*mx){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	else if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
		}
		cout<<ans;
	}
	
	return 0;
}

