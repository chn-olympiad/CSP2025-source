#include<bits/stdc++.h>
using namespace std;
long long w,no,rs,ans,r,n,m,c[100005];
char s[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c,c+n+1);
	for(int i=1;i<=n;i++) {
		r++;
		if(s[i]==0) {
			no++;
			rs++;
		}
		if(r>=c[i]) no++;
		if(rs==w) {
			ans++;
//			break;
		}
	}
	cout<<ans*2;
	return 0;
}
