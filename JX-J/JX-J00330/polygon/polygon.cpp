#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n,c=0;
int a[N];
void find(int num,int s,int sum,int maxn){
	if(s>=3&&maxn*2<sum){
		c=(c+1)%mod;
	}
	for(int i=num+1;i<=n;i++){
		find(i,s+1,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		find(i,1,a[i],a[i]);
	}
	cout<<c;
	return 0;
}
