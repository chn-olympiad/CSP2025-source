#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],l,r,t;
bool cut(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+(n*m)+1,cut);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	l=(t-1)/n+1;
	if(l%2==0){
		r=n*l+1-t;
	}else{
		r=t-n*(l-1);
	}
	cout<<l<<" "<<r;
	return 0;
}
