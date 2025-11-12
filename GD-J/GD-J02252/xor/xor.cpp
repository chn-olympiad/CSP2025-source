#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=66666;
stringstream ss;
string s;
int t,a[N],x,y,n,m,k,c,d;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)x=1,d++;
		if(a[i]==0)c++;
	}
	if(x==0)cout<<n;
	else cout<<max(c,d);
	return 0;
}
