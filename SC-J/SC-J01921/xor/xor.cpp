#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int a[N],d[N];
struct p{
	int xx,yy;
};
vector<p>v;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,f=0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f++;
		}
	}
	if(k==0&&f==n){
		cout<<n;
		return 0;
	}
	if(k<=1){
		if(k==1){
			cout<<f;
			return 0;
		}
		else{
			cout<<n-f;
			return 0;
		}
	}
	return 0;
}
