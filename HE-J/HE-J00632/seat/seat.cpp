#include <bits/stdc++.h>
using namespace std;
int n,m,a[111],c,x,y,b;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;a[i-1]!=c;i++){
		if(a[i]==c){
			b=i;
			break;
		}
	}
	x=b/n;
	y=b%n;
	if(x%2){
		if(!y) cout<<x<<' '<<n;
		else cout<<x+1<<' '<<n-y+1;
	}else{
		if(!y) cout<<x<<' '<<1;
		else cout<<x+1<<' '<<y;
	}
	return 0;
}

