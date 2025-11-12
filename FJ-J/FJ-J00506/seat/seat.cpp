#include<bits/stdc++.h>
using namespace std;
int n,m,jz,pm=1,bj;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>bj;
	for (int i=2;i<=m*n;i++){
		int a;
		cin>>a;
		if (a>bj) pm++;
	}
	if (pm%n==0){
		cout<<pm/n<<" ";
		if ((pm/n)%2==0) cout<<1;
		else cout<<n;
	}
	else{
		cout<<(pm/n)+1<<" ";
		if (((pm/n)+1)%2==0) cout<<n-(pm%n)+1;
		else cout<<pm%n;
	}
	return 0;
}

