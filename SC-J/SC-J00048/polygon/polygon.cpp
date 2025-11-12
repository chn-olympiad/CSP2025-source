#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 105
int a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(ll i = 0;i<n;i++)cin>>a[i];
	if(n <= 2){
		cout<<0;
		return 0;
	}
	int cnt = 0;
	int maxs = -1;
	for(int i = 0;i<n;i++){
		cnt += a[i];
		maxs = max(maxs,a[i]);
	}
	if(cnt > 2*maxs)cout<<1;
	else cout<<0;
	return 0;
	
}