#include<bits/stdc++.h>
using namespace std;
int n,a[24524],t,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>t) t=a[i];
		ans=ans+a[i];
		}
	if(n==3){
		if(ans>t*2) cout<<"1";
		else cout<<"0";
		}
	

return 0;
}
