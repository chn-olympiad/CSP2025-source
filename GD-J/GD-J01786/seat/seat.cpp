#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt=0;
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>r)cnt++;
	}
	if((cnt/n)%2==0){
		cout<<cnt/n+1<<" "<<cnt-cnt/n*n+1;
	}
	else cout<<cnt/n+1<<" "<<cnt/n*(n+1)-cnt+1;
	return 0;
}
