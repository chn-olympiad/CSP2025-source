#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int n,a[N];

signed main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	if(n==3 && a[1]+a[2]>a[3]) cout<<1;
	else if(n==3) cout<<0;
	else cout<<"YOU HAVE NO EGG!";
	
	return 0;
	
}
//Æ­12·ÖÁËÊÂ 
