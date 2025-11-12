#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m,a1,a,nus=1,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a1;
	for(int i=0;i+1<n*m;i++){
		cin>>a;
		if(a>a1)nus++;
	}
	b=nus/n;
	c=nus%n;
	if(b==0)cout<<1<<" "<<c;
	else{
		if(c==0){
			if(b%2==0)cout<<b<<" "<<1;
			else cout<<b<<" "<<n;
		}
		else{
			if(b%2==0)cout<<b+1<<" "<<c;
			else cout<<b+1<<" "<<n-c+1;
		}
	}
	return 0;
}
