#include<bits/stdc++.h>
#define M 100010
using namespace std;
int t,n,ans,q;
int a[M][4],a1[M];
struct nailong{
	int val,club,pos;
};
void cleareset(){
	ans=0;
	memset(a1,0,sizeof(a1));
}
bool cmp(nailong a,nailong b){
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;q=1;
		cleareset();
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a[i][2]>>a[i][3];
			if(!a[i][2]&&!a[i][3])q=0;
			else ans+=max(a1[i],max(a[i][2],a[i][3]));
		}
		if(q){
			sort(a1+1,a1+n+1);
			for(int i=n;i>=1;i--){
				ans+=a1[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
