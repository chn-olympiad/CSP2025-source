#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt=1;
int x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=2;i<=n*m;++i){
		cin>>x;
		if(x>t)++cnt;
	}
	int lie=(cnt-1)/n+1;
	int hang=lie*n-cnt+1;
	if(lie%2==1)hang=n-hang+1;
	cout<<lie<<" "<<hang;
	return 0;
} 


