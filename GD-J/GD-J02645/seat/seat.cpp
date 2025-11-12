#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,r,idx,x,y,st,s[102];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	r=s[1];
	sort(s+1,s+(n*m)+1,cmp);
	idx=1;
	while(s[idx]!=r) idx++;
	y=ceil(idx*1.0/n);
	st=idx-(n*(y-1));
	if(y%2) x=st;
	else x=n-st+1;
	cout<<y<<' '<<x;
	return 0;
}
