#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int r,anj=0;
	int s;
	cin>>n>>m;
	cin>>r;
	for(int i=0;i<n*m-1;i++){
		cin>>s;
		if(s>r)anj++;
	}
	cout<<anj/n+1<<" "<<anj%n+1;
	return 0;
}
