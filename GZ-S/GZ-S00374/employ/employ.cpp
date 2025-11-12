//GZ-S00374 遵义市第四初级中学 聂宇东
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define forr(a,n) for(int a=0;a<n;a++)
const ll N=998244353;
ll jc(ll a){
	int sum=1;
	for(int i=1;i<=a;i++){
		sum*=i;
		sum%=N;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>n;
	string s;
	cin>>s;
	int c[n+1];
	forr(i,n){
		cin>>c[i];
	}
	cout<<jc(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

