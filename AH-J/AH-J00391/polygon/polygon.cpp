#include<bits/stdc++.h>
using namespace std;
int n,a[5100],b[5100],maxx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    maxx=max(maxx,a[i]);	
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
	   cout<<1; return 0;
	}
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	if(a[n]*2<b[n])cout<<1;
	else cout<<0;
	return 0;
}
