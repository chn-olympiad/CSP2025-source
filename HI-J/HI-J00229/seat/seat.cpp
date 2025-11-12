#include <bits/stdc++.h>
using namespace std;
int a[10010];
int n,m,x=1,y=1,tz,tw;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1 ; i<=n*m ; i++){
		cin>>a[i];
	} 
	
	tz=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1 ; i<=n*m ; i++){
		if(a[i]==tz)	tw=i;
	}
	
	while(tw>n){
		x++;
		tw=tw-n;
	}
	y=tw;
	if(x%2==0)	y=n-tw+1;
	cout<<x<<' '<<y;
	return 0;
}
