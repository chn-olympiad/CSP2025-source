#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int a[N],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1],p=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x)p=i;
	int b=p/n;
	
	if(p%n!=0)b++;
	cout<<b<<' ';
	
	if(b%2==1){
		if(p%n==0)cout<<n<<'\n';
		else cout<<p%n<<'\n';
	}else{
		if(p%n==0)cout<<1<<'\n';
		else cout<<n-p%n+1<<'\n';
	}
	
	return 0;
}
