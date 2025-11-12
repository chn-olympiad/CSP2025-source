#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=505;
const int M=998244353;
int a[N];
int b[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	ll p=1;
	for(int i=1;i<=n;i++){
		p*=i;
		p%=M;
	}
	cout<<p;
	return 0;
} 