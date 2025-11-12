#include <bits/stdc++.h>
using namespace std;
const long long N=2000009;
long long n,q;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (long long i=1;i<=n;i++) cin>>a[N]>>b[N];
	for (long long i=1;i<=q;i++){
		string aa,bb;
		long long ans=0;
		cin>>aa>>bb;
		for (long long j=1;j<=n;j++){
			if (a[i].size()<aa.size()) ans++;
		}
		cout<<ans-1<<endl;
	}
	return 0;
	//0
}

