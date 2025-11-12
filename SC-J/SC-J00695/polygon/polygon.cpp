#include<bits/stdc++.h>
using namespace std;

const int N=5000;
const long long mod=998244353;

int n,sum,cnt;
int a[N];

bool cmp(int x,int y){
	return x>y; 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	int maxx=a[1];
	if(sum>=maxx*2) cnt++;
	cout<<cnt%mod;
	return 0;
}