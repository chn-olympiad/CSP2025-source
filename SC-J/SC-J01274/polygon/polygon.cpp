#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
int a[5010];
int maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		maxx=max(a[i],maxx);
	}
	if(cnt>maxx*2)cout<<1;
	else cout<<0;
	return 0;
} 