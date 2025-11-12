#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1005][1005],b[100005];
int len[100005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		len[i]=strlen(a[i]);
	}
	while(m--){
		int ans=0;
		cin>>b;
		cout<<ans<<endl;
	}
	return 0;
}