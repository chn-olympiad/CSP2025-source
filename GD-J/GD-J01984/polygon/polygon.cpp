#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n;
int a[maxn];
long long sum;
int ma;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=3;i++){
			cin>>a[i];
			sum+=a[i];
			ma=max(a[i],ma);
		}
		if(sum>2*ma) cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
} 
