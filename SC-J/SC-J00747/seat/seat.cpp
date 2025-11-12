#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],p,r,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+l);
	for(int i=1;i<=l;i++){
		if(a[i]==r){
			w=l-i+1;
			break;
		}
	}
	if(w%n==0){
		if((w/n)%2==1){
			cout<<w/n<<' '<<n;
		}
		else {
			cout<<w/n<<' '<<1;
		}
	}
	else {
		p=w/n+1;
		if(p%2==0){
			cout<<p<<' '<<n+1-(w%n);
		}
		else {
			cout<<p<<' '<<w%n;
		}
	}
	return 0;
}