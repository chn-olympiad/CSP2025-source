#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,wo,pos=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	wo=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==wo){
			pos=i;
			break;
		}
	int l=(pos-1)/n+1,md=pos%n;
	if(md==0)md=n;
	if(l%2==0)md=n-md+1;
	cout<<l<<' '<<md;
	return 0;
}

