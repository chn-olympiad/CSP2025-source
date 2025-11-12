#include<bits/stdc++.h>
using namespace std;
int n,m,R,s,c=1,r=1;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<s;i++) cin>>a[i];
	if(m==1&&n==1){
		cout<<"1 1";
		return 0;
	}
	R=a[0];
	sort(a,a+s);
	for(int i=0;i<s;i++){
		if(a[i]==R){
			c=s/m;
			r=s/n;
			cout<<c<<" "<<r;
		}
	}
	retur 0;
}
