#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct op{
	bool r;
	ll ans;
}a[10000];
bool qwq(op x,op y){
	return x.ans>y.ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,hang,lie,siter;
	double g;
	cin>>n>>m;
	for(ll i=0;i<n*m;i++){
		cin>>a[i].ans;
		a[i].r=false;
	}
	a[0].r=true;
	sort(a,a+n*m,qwq);
	for(ll i=0;i<n*m;i++){
		if(a[i].r==true){
			siter=i+1;
			break;
		}
	}
	g=siter;
	lie=ceil(g/n);
	if(lie%2!=0){
		hang=siter%n;
		if(hang==0) hang=m;
	}
	else{
		hang=n-(siter/n)+1;
	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
