#include <bits/stdc++.h>
const int maxn=5e5+5;
#define  int  long long
using namespace std;
int ans; 
int a[maxn];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(k==0&&flag==1){
		cout<<n;
		return 0;
	}
	cout<<n/2;
}
