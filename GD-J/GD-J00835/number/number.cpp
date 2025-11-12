#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n;
string a;
int ans[N],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	a=' '+a;
	n=a.size()-1;
	for(int i=1;i<=n;i++){
		if(a[i]-'0'<=9&&a[i]-'0'>=0){
			ans[++cnt]=a[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1);
	if(ans[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--)cout<<ans[i]; 
}
