#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long LL;

int t;
int n;
int a[N][4];
int b[N];int idx;
//pf
int main(){
	//!!!freopen!!!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		LL res = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
			b[++idx] = a[i][1];
		}
		sort(b+1,b+idx+1);
		for(int i=n;i>n/2;i--) res+=b[i];
		cout<<res<<'\n';
	}
	return 0;
}
//Shawty its so freaking heartache
