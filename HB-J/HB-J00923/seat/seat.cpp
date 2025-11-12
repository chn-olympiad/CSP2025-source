#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,grade=1;
	cin>>n>>m;
	int R;
	cin>>R;
	for(int i=1;i<m*n;i++){
		int x;cin>>x;
		if(x>R) grade++;
	}
	int x=grade/n;
	int y=grade%n;
	if(y==0){
		if(x%2==1) cout<<x<<" "<<n;
		else cout<<x<<" "<<1;
	}
	else{
		if(x%2==1) cout<<x+1<<" "<<n-y+1;
		else if(x%2==0) cout<<x+1<<" "<<y;
	}
	return 0;
}
