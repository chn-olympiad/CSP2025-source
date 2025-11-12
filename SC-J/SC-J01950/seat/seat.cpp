#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[105];
bool cmp(int b,int c){return b>c;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	cin>>a[1];
	int c=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)if(a[i]==c){pos=i;break;}
	if(pos%(2*n)>n)cout<<ceil(1.0*pos/n)<<" "<<n+1-(pos%n);
	else if(pos%(2*n)==n)cout<<ceil(1.0*pos/n)<<" "<<n;
	else cout<<ceil(1.0*pos/n)<<" "<<pos%n;
	return 0;
}