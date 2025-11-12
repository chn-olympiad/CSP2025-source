#include<bits/stdc++.h>
#define int long long
using namespace std;
int op1[505];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int sum=0;
	int l=0;
	int sum1=0;
	int has=0;
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		sum+=op;
		op1[i]=op;
		if(op==1){
			has+=(sum1<2);
		}
		else{
			sum1++;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=1){
			l=1;
		}
	}
	if(l==0){
		if(has<n){
			cout<<0;
		}
	}
	return 0;
}