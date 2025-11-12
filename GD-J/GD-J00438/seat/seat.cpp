#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,a[105],l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])ans++;
	}
	if(ans%n!=0)l=1;
	l+=ans/n;
	cout<<l<<' ';
	h=(ans-1)%n+1;
	if(l%2==0)cout<<n+1-h;
	else cout<<h;
	cout<<" "<<ans;
	return 0;
}

