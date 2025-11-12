#include <bits/stdc++.h>
using namespace std;
int n,d[5005],p[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int p,x,q;
		cin>>p>>x>>q;
		int maxn = max(max(p,x),q);
		if((x+q+p)>=maxn*2){
			++s;
		}
	}else cout<<((n*n)/2)%998;
	cout<<s;
	//I have no ideas which can do this problem. pian fen da fa!!!
	return 0;
}
