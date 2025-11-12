#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+5;
int t,n;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		int mid=n/2;
		for(int i=1;i<=n;i++){
			int a2,a3;
			cin>>a[i]>>a2>>a3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=mid;i++) ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}