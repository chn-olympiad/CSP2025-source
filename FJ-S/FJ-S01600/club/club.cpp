#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][5],cnt[5];
int T,n,ans;
struct ccf{
	int choice1,choice2,maxn;
}zys[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxn=max(a[i][j],maxn);
			}
			ans+=maxn;
		}
		cout<<ans<<endl;
		ans=0;
	
	}
	return 0;
}
// I LOVE ZYS!!!！！！！！！by sjbyw
