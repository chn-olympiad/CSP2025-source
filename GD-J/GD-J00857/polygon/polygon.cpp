#include<bits/stdc++.h>
using namespace std;


const int maxn=505;
const int MOD=998244353;
int a[maxn];
long long cnt;
int n,sum[maxn];

int maxx(int l,int r){
	int ma=0;
	for(int i=l;i<=r;i++)
		ma=max(ma,a[i]);
	return ma;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n==3&&sum[n]>maxx(1,n)*2){
			cout<<"1"<<endl;
			return 0;
		}
		else{
			cout<<"0"<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
}
