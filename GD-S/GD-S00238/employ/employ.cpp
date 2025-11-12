#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[502],p[502],a[502],ans;
bool s[502];
string inp;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>inp;
	for(int i=0;i<n;i++) s[i+1]=inp[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int pre=0,cnt=n;
		for(int i=1;i<=n;i++){
			if((s[i]==0)||(pre>=c[p[i]])){
				cnt--,pre++;
			}
		}
		ans+=(cnt>=m);
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
//Eight scores are alse scores
