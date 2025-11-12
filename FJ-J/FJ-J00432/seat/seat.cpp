#include<bits/stdc++.h>
#define  ll  long long
using namespace std;
const int N=INT_MAX;
ll n,m,c,r,a[1005],s[1005][1005],b=1,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=n*m;
	o=a[1];
	sort(a+1,a+n*m+1);
	for(ll i=1;i<=n;i++){
		if(i%2==1){
			for(ll j=1;j<=m;j++){
			    s[j][i]=a[b];
			    if(s[j][i]==o){
			     	cout<<i<<' '<<j<<endl;
			     	return 0;
				 }
			     b--;
		    }
		}
		else if(i%2==0){
			for(ll j=m;j>=1;j--){
			     s[j][i]=a[b];
			     if(s[j][i]==o){
			     	cout<<i<<' '<<j<<endl;
			     	return 0;
				 }
			     b--;
		    }
		}
	}
	return 0;
}
