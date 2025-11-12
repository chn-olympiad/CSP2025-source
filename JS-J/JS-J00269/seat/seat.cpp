#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a[105],key=1,c,r;
int cal(int a,int b){
	if(a%b==0)return a/b;
	return a/b+1;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])key++;
	}
	c=cal(key,n);
	if(c%2==1)r=key-(c-1)*n;
	else r=m-(key-(c-1)*n)+1;
	cout<<c<<' '<<r;
	return 0;
}
