#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,maxn,sum;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>maxn*2)cout<<1;
	else cout<<0;
	
	return 0;
}
