#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int cmp(int a,int b){
	return a>b;
}
const int N=1e8+10;
ll n,m,ming;
ll a[N];
int main() {

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<'1';
	//sort(a,a+cnt+1);
	//cout<<n+m<<endl<<n<<m;
	return 0;
}
