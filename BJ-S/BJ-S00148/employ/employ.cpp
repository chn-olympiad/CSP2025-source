#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
int a[N],b[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long ans=1;
	for(int i=2;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}
