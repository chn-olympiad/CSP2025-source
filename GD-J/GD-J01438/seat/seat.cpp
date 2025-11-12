#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	int a[111];
	int n,m;
	
	int ceil(int x,int y){
		return x/y+bool(x%y);
	}
	
	int main(){
		#ifndef debug
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		cin>>n>>m;
		int r,rank=1;
		cin>>r;
		for(int i=2;i<=n*m;i++){
			cin>>a[i];
			if(a[i]>r)rank++;
		}
		
		int y=ceil(rank,n);
		int x=y&1?((rank-1)%n+1):(n-((rank-1)%n+1)+1);
		cout<<y<<" "<<x<<endl;
		return 0;
	} 
}
int main(){
	zcy::main();
	return 0;
}
