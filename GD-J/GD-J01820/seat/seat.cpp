#include<bits/stdc++.h>
using namespace std;

const int N=15;
int n,m,x,pos;
int a[N*N];

bool cmp(int s,int w){
	return s>w;
}

signed main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++) 
		if(a[i]==x){
			pos=i;
			break;
		}
	
	int u,v;
	u=pos%n? pos/n+1:pos/n;
	if(u&1) v=pos%n? pos%n:n;
	else v=pos%n? n-pos%n+1:1;
	
	cout<<u<<" "<<v;
	
	return 0;
	
}
//CCF! no droping point plz!
