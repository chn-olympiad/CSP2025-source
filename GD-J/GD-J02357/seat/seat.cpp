#include<iostream>
using namespace std;
int n,m,R,O,cnt=1;
int cl(int a,int b){
	if(a%b) return a/b+1;
	else return a/b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>R;
	for(int i=1;i<n*m;i++){
		cin>>O;
		if(O>R) cnt++;
	} 
	int c=cl(cnt,n),r=cnt%(2*n);
	if(r>n) r=2*n-r+1;
	cout<<c<<' '<<r;
}
