#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s,rsc,rid=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>rsc;
	for(ll i=2;i<=n*m;i++){
		cin>>s;
		if(s>rsc){
			rid++;
		}
	}
	x=(rid+(n-1))/n;
	if(x%2==0){
		y=n-(rid%n)+1;
	}else if(x%2!=0){
		if(rid%n==0){
			y=n;
		}else{
			y=rid%n;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
