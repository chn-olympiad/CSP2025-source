#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct node{
	int sc,num;
}a[N];
bool cmp(node a,node b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].num=i;
	}
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1)cnt=i;
	}
	int x=ceil(cnt*1.0/n),y=cnt%n;
	if(y==0)y=n;
	if(x%2==0)cout<<x<<" "<<n+1-y;
	else cout<<x<<" "<<y;
	return 0;
}