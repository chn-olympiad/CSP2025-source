#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;

int n,m;
int x,ans;
int c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2,a;i<=n*m;i++){
		cin>>a;
		if(a>x)ans++;
	}ans++;
	if(ans%n){
		c=ans/n+1;
		r=ans-(c-1)*n;
	}else{
		c=ans/n;
		r=n;
	}
	if(c&1){
		cout<<c<<" "<<r;
	}else{
		if(ans%n)cout<<c<<" "<<(n-(r-1));
		else cout<<c<<" "<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}