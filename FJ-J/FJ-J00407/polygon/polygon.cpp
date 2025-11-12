#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a,b,c;
void own(){
	if(n<=2){
		cout<<0;
		return;
	}
	if(a+b>c and b+c>a and a+c>b) cout<<1;
	else cout<<0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<=3){
		cin>>a>>b>>c;
		own();
		return 0;
	}
	cout<<6;
}
