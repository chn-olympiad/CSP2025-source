#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[110];
bool cmp(int a,int b){
	return a>b;
}
int ch(int t,int n){
	if(t%n>0)return t/n+1;
	return t/n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==t){t=i;break;}
	int rm=ch(t,n);
	if(rm%2==0)cout<<rm<<" "<<n+1-(t%n==0?n:t%n);
	else cout<<rm<<" "<<(t%n==0?n:t%n);
	return 0;
}
