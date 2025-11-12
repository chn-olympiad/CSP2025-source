#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[1005];
int n,m,bj,t1,t2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n*m;i++)
		cin>>x,a[i]={x,i};
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i].second==1)bj=n*m-i+1;
	t1=(bj-1)/n+1,t2=(bj-1)%n+1;
	if(t1%2==0)t2=n-t2+1;
	cout<<t1<<" "<<t2;
	return 0;
}