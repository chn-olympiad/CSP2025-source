#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 105
int n,m,a[N],ans=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1)continue;
		if(a[i]>a[1])++ans;
	}
	int a=ans/n;
	int b=ans%n;
	if(b!=0)cout<<a+1<<' ';
	else cout<<a<<' ';
	if(a%2==1&&b==0)cout<<m-b;
	else if(a%2==1&&b!=0)cout<<m-b+1;
	else if(a%2==0&&b==0)cout<<m-b+1;
	else cout<<b;
	return 0;
}
