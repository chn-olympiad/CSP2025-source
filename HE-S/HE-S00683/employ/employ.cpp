#include<bits/stdc++.h>
using namespace std;
#define LL long long
unsigned long long jiec(LL a,LL b){
	unsigned long long ans=1;
	while(a!=b){
		
		ans*=a;
		ans%=998244353;
		a--;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,c[600]={0},ans=0,sum=1;
	string N;
	cin>>n>>m;
	cin>>N;
	for(int i=1;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	int p=0;
	for(int i=0;i<n;i++){
		if(c[i]<=p){
		ans++;p++;
		}
	}
	cout<<jiec(ans,ans-m)%998244353;
	return 0;
}
