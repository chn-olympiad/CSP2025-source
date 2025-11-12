#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,t,a[100005],n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			k=n*m-i+1;break;
		}
	}
	cout<<(k-1)/n+1<<" ";
	k%=2*n;
	cout<<(k>n?2*n-k+1:(!k?1:k));
	return 0;
}