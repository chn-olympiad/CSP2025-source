#include<bits/stdc++.h>
using namespace std;
long long n,t,a[1000010],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(a[i],max(a[i-1],a[i-2]));
		}
	} 
	cout<<ans;
	return 0;
} 

