#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int cnt=0,maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		cnt+=a[i];
	}
	if(cnt>2*maxn) cout<<1;
	else cout<<0;
	return 0;
}