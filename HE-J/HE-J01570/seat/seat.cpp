#include<bits/stdc++.h>
using namespace std;
struct P{
	int id;
	int mark;
};
bool cmp(P x,P y){
	return x.mark>y.mark;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	P a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int xx;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			xx=i;
		}
	}
	int l=xx/n,h=xx%n;
	if(h==0){
		h+=n;
	}
	if(xx!=n){
		l++;
	}
	if(l%2==0){
		cout<<l<<" "<<n-h+1;
	}
	else{
		cout<<l<<" "<<h;
	}
	return 0;
}
