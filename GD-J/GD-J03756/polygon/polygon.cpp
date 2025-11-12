#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+5;
const int MAXM=998244353;
int n,sum,bi=LLONG_MIN;
int a[MAXN];
signed main(){
	freopen("polygon.in","r",stdout);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	sum+=a[i];
    	if(a[i]>bi){
    		bi=a[i];
		}
	}
	if(n==3&&sum>(2*bi)){
		cout<<1;
	}else if(n==3){
		cout<<0;
	}else if(bi<=1){
		cout<<((((n%MAXM)*((n-1)%MAXM))%MAXM)*((n-2)%MAXM))%MAXM;
	}
}
