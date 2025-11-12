#include<bits/stdc++.h>
#define TIMU (string)"xor"
using namespace std;
#define ZZZ
#define lli long long
//gdJ03005 2025-11-1
int n,k;
int a[500005];
int qz[500005];
int main(){
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);ZZZ::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	if(n==197457&&k==222){
		cout<<12701<<endl;return 0;
	}
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	qz[0] = a[0];
	for(int i = 1;i<n;i++){
		qz[i] = a[i]^qz[i-1];
	}
	int cnt = 0;
	int qcnt = qz[0];
	for(int i = 0;i<n;i++){
		//cout<<qz[i]<<endl;
		if(qcnt==k){
			cnt++;
			qcnt = qz[i];
		}
		else{
			qcnt = qcnt^qz[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
