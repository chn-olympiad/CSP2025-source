#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[107];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t,f;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			f=i;
			break;
		}
	}
	if((f/n)%2==0){
		if(f%n==0)	cout<<f/n<<" "<<1;
		else	cout<<f/n+1<<" "<<f%n;
	}
	else{
		if(f%n==0)	cout<<f/n<<" "<<n;
		else	cout<<f/n+1<<" "<<n-f%n+1;
	}
	return 0;
}