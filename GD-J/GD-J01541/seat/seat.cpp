#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,i;
struct node{
	int sc;
	bool f=false;
}s[101];
bool cmp(node a,node b){return a.sc>b.sc;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s[1].sc;
	s[1].f=true;
	for(i=2;i<=n*m;i++)cin>>s[i].sc;
	sort(s+1,s+n*m+1,cmp);
	for(i=1;i<=n*m;i++)if(s[i].f)break;
	c=ceil((double)i/n);
	if(c%2==1)r=n-(n*c-i);
	else r=n*c-i+1;
	cout<<c<<' '<<r;
	return 0;
}
