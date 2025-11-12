#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>2*maxn)cout<<1;
	else cout<<0;
//	for(int i=1;i<=n;i++)
	return 0;
} 
