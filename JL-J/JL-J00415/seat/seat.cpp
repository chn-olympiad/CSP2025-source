#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,n,m,t,k=1;
	cin>>n>>m>>t;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>t){
			k++;
		}
	}int l=k/n+1;
	int h=k%n;
	if(h==0){
		l--;
		h=n;
	}if(l%2==1){
		cout<<l<<' '<<h;
	}else{
		cout<<l<<' '<<n-h+1;
	}return 0;
}
