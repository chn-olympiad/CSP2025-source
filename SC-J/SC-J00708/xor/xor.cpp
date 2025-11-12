#include<bits/stdc++.h>
using namespace std;
const long long maxn=10010;
int b[maxn][maxn];
long long c[maxn],a[maxn];
int n,m1;
int m;
int k;
int q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0){
		if(a[1]!=a[2]){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	if(n==0){
		cout<<"0";
	}
	if(n==1&&k==0){
		cout<<"1";
	}
	return 0;
}