#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
string s;
const int mod=998244353; 
int c[1000005],cnt=0,a[1000005]; 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//最后一题，，，  
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}for(int i=1;i<=m;i++){
		cin>>c[i];
		a[c[i]]++;
		cnt=max(cnt,a[c[i]]);
	}cout<<cnt*(cnt+1)/2;
	//咱们就当他过了吧 
	return 0;
}
