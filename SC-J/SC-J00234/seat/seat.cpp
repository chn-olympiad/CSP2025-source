#include<bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 15;

bool f;
int n,m,x,y=1;

struct node{
	int x,id;
	
	bool operator<(const node& y)const {
		return x>y.x;
	}
}a[N*N];

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i].x;
		a[i].id=i;
	}
	
	std::sort(a+1,a+1+n*m);
	
	for(int i=1;i<=n*m;i++){
		if(f)x--;
		else x++;
		if(x==0||x==n+1){
			x=(x==0?1:n);
			f=1-f;
			y++;
		}
		if(a[i].id==1){
			std::cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}