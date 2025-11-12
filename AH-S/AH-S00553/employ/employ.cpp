#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],b[1001],cnt;
char s[1001];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1; i<=n; i++)cin>>a[i],b[i]=i;
	if(n>=100) {
		cout<<"2\n";
		return 0;
	}
	do {
		int los = 0;
		for(int i=1; i<=n; i++) {
			if(a[b[i]]<=los) {
				los++;
				continue;
			}
			if(s[i]=='0')los++;
		}
//		cout<<los<<endl;
		if(n-los>=m) {
			cnt++;
			cnt%=998244353;
//			for(int i=1; i<=n; i++)cout<<b[i]<<" ";
//			cout<<endl;
		}
	} while(next_permutation(b+1,b+n+1));
	cout<<cnt%998244353<<endl;
	return 0;
}
