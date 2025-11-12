#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int n,m;
int a[N];
int ans,now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m) ans++,now=0;
		else{
			now^=a[i];
			if(now==m) ans++,now=0;
		}
	}
	cout<<ans;
	return 0;
}
