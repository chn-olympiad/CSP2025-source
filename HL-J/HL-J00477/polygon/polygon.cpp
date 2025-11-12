#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=0,l=0;
int a[N],maxn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		l+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n>=3&&maxn*2<l)ans++;
	cout<<ans;
	return 0;
}
