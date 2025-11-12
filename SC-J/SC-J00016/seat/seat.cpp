#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,x,y,a1,ia;
int g[150];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>g[i];
	a1=g[1];
	sort(g+1,g+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(g[i]==a1){
			ia=i;break;
		}
	y=ia/n+1;
	if(ia%n==0) y--;
	int m=ia%n;
	if(!m) m=n;
	if(y%2) x=m;
	else x=n-m+1;
	cout<<y<<" "<<x;
	return 0;
} 