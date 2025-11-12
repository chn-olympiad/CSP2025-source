#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int s[111];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>s[i];
	}
	int x=s[1],y,r,c;
	sort(s+1,s+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(s[i]==x){
			y=i;
		}
	}
	c=(y+n-1)/n;
	y=y%(2*n);
	if(y>n){
		r=n+n-y+1;
	}else{
		r=y;
	}
	cout<<c<<" "<<r;
	return 0;
}
