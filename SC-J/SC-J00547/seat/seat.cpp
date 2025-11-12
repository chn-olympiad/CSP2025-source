#include<bits/stdc++.h> 
using namespace std;
int up(int b,int c){
	int ans=b/c;
	if(b%c) return ans+1;
	return ans;
}
int qu(int b,int c){
	int ans=b%c;
	if(ans) return ans;
	return c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,person,sum=1,a,x,y;
	cin>>n>>m;
	cin>>person;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>person) sum++;
	}
	x=up(sum,m);
	y=qu(sum,m);
	if(x%2==0) y=m+1-y;
	cout<<x<<' '<<y;
	return 0;
}