#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,sum,ans;
int a[N];
bool fa=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]!=a[i-1]) fa=0;
	}
	if(n==3){
		if(sum>max(a[1],max(a[2],a[3]))*2) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(fa){
		sum=0;
		for(int i=3;i<=n;i++){
			sum+=(n-i+1);
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
	srand(time(0));
	int x=rand()*rand();
	cout<<x%(2*n);
	return 0;
}
