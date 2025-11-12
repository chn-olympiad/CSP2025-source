#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int n,m,a[110],aaa,ai,c,r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	aaa=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aaa){
			ai=i;
			break;
		}
	}
	c=((ai-1)/n+1);
	if((c%2)==1) r=((ai%n==0)?n:(ai%n));
	else r=((ai%n==0)?1:(n-ai%n+1));
	cout<<c<<' '<<r;
	return 0;
}
