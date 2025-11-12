#include<bits/stdc++.h>
using namespace std;
int n,m,R,a,cnt=1,c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>R)cnt++;
	}
	while(--cnt){
		if(c%2)r++;
		else r--;
		if(r>n){
			r-=n;
			c++;
			if(c%2==0)r=n-r+1; 
		}else if(r==0){
			r=1,c++;
		}
	}cout<<c<<' '<<r;
	return 0;
}
