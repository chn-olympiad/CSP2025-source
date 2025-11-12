#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;

int n,m;
int a[20][20];
struct node{
	int w,id;
	bool operator <(const node&W)const{
	    return w>W.w;
	}
}g[400];

signed main(){
	ios::sync_with_stdio(0);std::cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i].w;
		g[i].id=i;
	}
	sort(g+1,g+1+n*m);
	int j=0;
	for(int i=1;i<=n*m;i++){
		if(g[i].id==1){
		    j=i;
		    break;
		}
	}
	int k=(j+n-1)/n;
	cout<<k<<" ";
	if(k%2==1){
		cout<<j-k*n+n;
	}else{
		cout<<k*n-j+1;
	}
	return 0;
}

