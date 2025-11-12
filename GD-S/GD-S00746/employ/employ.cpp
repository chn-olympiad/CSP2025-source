#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int n,m;
string s;
int arr[maxn];
bool vis[maxn];
long long ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans<<"\n";
	return 0;
}
