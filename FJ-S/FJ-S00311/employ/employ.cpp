#include<bits/stdc++.h>
using namespace std;
long long sum=1,k=998244353;
int n,m,a[505],tot;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<s.size();i++) if(s[i]=='0') tot++;
    for(int i=1;i<=n;i++){
    	sum*=i;
    	sum%=k;
	}
	if(n-tot>=m) cout<<sum;
    else cout<<0;
    return 0;
}