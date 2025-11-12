#include<bits/stdc++.h>
using namespace std;
int n,m;
bool k;
struct N{
	int x;
	bool l;
}p[110];
bool cmp(N a,N b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p[1].l=true;
	for(int i=1;i<=n*m;i++){
		cin>>p[i].x;
	}
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(p[i].l){
			if(i%n){
				cout<<i/n+1<<" ";
				if((i/n+1)%2)cout<<i%n;
				else cout<<n-i%n+1;
			}else{
				cout<<i/n<<" ";
				if((i/n)%2)cout<<n;
				else cout<<1;
			}
		}
	}
	return 0;
}
