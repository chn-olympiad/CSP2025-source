#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,k,a[N],r[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)_=0;
	}
	if(_){
		if(k>1)cout<<0;
		else{
			for(int i=1;i<=n;++i)ans+=a[i];
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		int sum=0;
		for(int j=i;j<=n;++j){
			sum^=a[j];
			if(sum==k){
				r[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		int _r=r[i];
		if(!_r)continue;
		for(int j=i;j<=_r;++j){
			if(r[j]<_r&&r[j]!=0){
				_r=r[j];
			}
		}
		i=_r;
		if(i<=n)ans++;
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
2
4 2
2 1 0 3
2
4 0
2 1 0 3
1
*/