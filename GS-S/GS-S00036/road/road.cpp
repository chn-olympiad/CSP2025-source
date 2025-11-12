#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a=INT_MAX,b=INT_MIN,n,m,k,x;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>x>>x>>x;
		b=max(x,b);
		a=min(x,a);
	}
	if(a!=0)cout<<(a+b)*a;
	else cout<<a+b;
	return 0;
}
