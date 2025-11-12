#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,s[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int p=s[1],q;
	sort(s+1,s+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(s[n*m-i+1]==p){
			q=i;
			break;
		}
	}
	cout<<(q-1)/n+1;
	if(((q-1)/n+1)%2) cout<<' '<<(q-1)%n+1;
	else cout<<' '<<m-(q-1)%n;
	return 0;
}
