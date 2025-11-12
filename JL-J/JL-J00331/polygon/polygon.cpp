#include<bits/stdc++.h>
using namespace std;
int stick[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
		ans+=stick[i];
	}
	ans/=n;
	if(ans>n){
		ans-=n;
	}else if(ans==n){
		ans++;
	}else{
		ans=ans+1+n;
	}
	cout<<ans;
	return 0;
}
