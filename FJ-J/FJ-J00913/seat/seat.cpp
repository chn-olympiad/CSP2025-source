#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])s++;
	}
	ans=s/n;
	if(ans%2==0)s=s%n;
	else s=n-1-s%n;
	cout<<ans+1<<" "<<s+1;
	return 0;
}

