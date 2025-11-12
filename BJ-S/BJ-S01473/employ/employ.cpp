#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
string s;
const int N=505;
int a[N];
ll mod=998244353;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=1,cnt=0;
	while(cnt<=m){
		cnt++;
		sum=sum*n%mod;
		n--;
	}
	cout<<sum%mod;
}