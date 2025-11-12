//GZ_S00508 »ÆºÆª Ê®°ËÖÐ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int dp[100010][10][4];
struct sb{
	int a,b,c;
};
sb a[100010];
bool cmp(sb a,sb b){
	if(a.a==b.a){
		if(a.b==b.b){
			return a.c>b.c;
		}
		return a.b>b.b;
	}return a.a>b.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,ans;cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++){
			ans+=a[i].a;
		}for(int i=n/2;i<n;i++){
			ans+=a[i].b;
		}
		cout<<ans<<endl;
	}
	return 0;
}
