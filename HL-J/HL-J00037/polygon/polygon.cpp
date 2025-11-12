#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,tmp,_sum,ans=0,_max,pown,now;
	cin>>n;
	pown=pow(2,n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<pown;i++){
		_sum=0;
		_max=0;
		now=n-1;
		tmp=i;
		while(tmp!=0){
			if((tmp&1)==1){
				_sum+=a[now];
				_max=max(_max,a[now]);
			}
			now--;
			tmp>>=1;
		}
		if(_sum>2*_max){
			ans++;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
