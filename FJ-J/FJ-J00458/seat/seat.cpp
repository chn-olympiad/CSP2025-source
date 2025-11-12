#include <bits/stdc++.h>
using namespace std;
int n,m,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>a) k++;
	}
	int u=k/n,v=k%n;
	if(v==0) cout<<u<<" ";
	else cout<<u+1<<" ";
	if(u%2==0&&v==0) cout<<1;
	else if(u%2==1&&v==0) cout<<n;
	else if(u%2==0) cout<<v;
	else cout<<n-v+1;
	return 0;
}

