#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int N=500005;
int n,k,p=0,ans=0,
	a[N],suma[N],sumt[N];
int xxor(int x,int y){
	int s=0,m=1;
	for(int i=0;i<20;++i){
		if(x%2!=y%2)	s+=m;
		x/=2;y/=2;
		m*=2;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	suma[i]=xxor(a[i],suma[i-1]);
	for(int i=1;i<=n;++i)	sumt[i]=xxor(suma[i],k);
	for(int i=1;i<=n;++i)
		for(int j=i-1;j>=p;--j)
			if(sumt[i]==suma[j]){
				ans++;
				p=i;
				break;
			}
	cout<<ans;
	return 0;
}
