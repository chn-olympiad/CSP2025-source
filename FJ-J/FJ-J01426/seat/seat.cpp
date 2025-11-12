#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100005],x,w;
int fd(int p){
	for(int i=1;i<=n*m;i++){
		if(a[i]==p)return i;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int p=fd(x);
	if(p%n==0)w=p/n;
	else w=p/n+1;
	cout<<w<<" "<<((w%2==1)?w%n+1:n-w%n);
	return 0;
}

