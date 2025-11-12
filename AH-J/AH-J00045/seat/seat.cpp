#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int s[20][20];
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,R;
	cin>>n>>m;
	x=n*m;
	for(int i=0;i<x;i++) cin>>a[i];
	R=a[0];
	sort(a,a+x);
	for(int i=x-1;i>=0;--i){
		if(R==a[i]) {
			R=(x-i);
			break;
		}
	}
	int h,l;
	if(R%n==0) l=R/n;
	else l=R/n+1;
	if(l%2==1){
		h=R%n;
		if(R%n==0) h=n;
	}
	else{
		h=n-R%n+1;
		if(R%n==0) h=1;
	}
	cout<<l<<' '<<h<<endl;
	return 0;
}
