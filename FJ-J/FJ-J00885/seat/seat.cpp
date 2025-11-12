#include<bits/stdc++.h>
using namespace std;
int l,n,m,node=1,biao,line,row;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>biao;
	for(int i=2;i<=n*m;i++){
		cin>>l;
		if(l>biao) node++;
	}
	
	if(node%n==0) line=(node/n);
	else line=(node/n)+1;
	cout<<line<<" ";
	if(line%2==0){
		
		 row=n+1-node%n;
	}
	else{
		
		row=node%n;
	}
	cout<<row;
	return 0;
}
