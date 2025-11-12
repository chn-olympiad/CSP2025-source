#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e3+4;
int n,a[maxn],last[maxn][maxn];
ll ans=0;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int he=0,maxs=0;
	for(int i=1;i<=3;i++){
		maxs=max(maxs,a[i]);
		he+=a[i];
	}
	if(he>maxs*2)ans++;
	cout<<ans;
	return 0;
}