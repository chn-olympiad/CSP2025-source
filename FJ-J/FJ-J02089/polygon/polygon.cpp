#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n;
int a[N],ans;
signed main(){
	ios::sync_with_stdio(0);std::cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		cout<<(a[1]+a[2]>a[3]);
	}
	if(n==4){
		cout<<(a[1]+a[2]>a[3])+(a[1]+a[3]>a[4]&&(a[2]!=a[3]||a[3]!=a[4]))+(a[3]+a[2]>a[4]&&a[2]!=a[1])+(a[1]+a[2]>a[4]&&a[4]!=a[3])+(a[1]+a[2]+a[3]>a[4]);
	}
	return 0;
}

