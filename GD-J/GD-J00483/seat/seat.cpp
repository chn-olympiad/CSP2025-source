#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,a[1145145],v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1],v=n*m;
	sort(a+1,a+v+1);
	while(j<=m){
		i=1,j++;
		while(i<=n){
			if(a[v]==k) cout<<j<<' '<<i,exit(0);
			i++,v--;
		}
		j++,i=n;
		while(i>=1){
			if(a[v]==k) cout<<j<<' '<<i,exit(0);
			i--,v--;
		}
	} 
}
