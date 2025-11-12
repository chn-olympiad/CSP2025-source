#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans1=1,ans2=1,ans3=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans1*=i;
	}
	for(int i=1;i<=m;i++){
		ans2*=i;
	}
	for(int i=1;i<=n-m;i++){
		ans3*=i;
	}
	cout<<ans1/ans3;
	return 0;
}

