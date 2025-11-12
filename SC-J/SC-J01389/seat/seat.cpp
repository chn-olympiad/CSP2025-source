#include<bits/stdc++.h>
using namespace std;
int d[105],R,pm=1,jou=0,hang=0;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>d[i];
	R=d[1];
	for(int i=1;i<=n*m;i++) {
		if(R<d[i]) pm++;
	}
	if(pm%n==0) cout<<pm/n<<" ";
	else cout<<pm/n+1<<" ";
	
	
	
	
	if(pm%n==0) jou=pm/n;
	else jou=pm/n+1;
	if(pm<=n) cout<<pm;
	else if(jou%2==1) cout<<pm%n;
	else{
		hang=n-(pm%n)+1;
		cout<<hang;
	}
	
	return 0; 
}