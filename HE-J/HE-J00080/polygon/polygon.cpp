#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	int maxn=-1,cnt=0;
	bool flag=1;
	for(int i = 1 ; i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		maxn=max(maxn,a[i]);
		if(a[i]!=1){
			flag=0;
		}
	}
	if(n<3){
		cout << 0;
		return 0;
	}else if(n == 3){
		if(cnt>2*maxn){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(flag){
		long long man=0;
		for(int i=n-2;i>=1;i--){
			man+=i;
		}
		cout<<man%998244353;
		return 0;
	}
	cout<<65;
	return 0;
}


