#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	a[0]=x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	x=lower_bound(a,a+n*m,x,cmp)-a;
	cout<<x/n+1<<" ";
	if(x/n+1&1){
		cout<<x%n+1;
	}
	else{
		cout<<m-x%n;
	}
	return 0;
}