#include <bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define ll long long //!!
int a[maxn][4];
int b[maxn];
int cnt_b=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cnt_b=0;
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		ll ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxx=max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxx==a[i][1]) cnt1++;
			else if(maxx==a[i][2]) cnt2++;
			else cnt3++;
			ans+=maxx;
		}
		int pos=-1;
		if(cnt1>n/2) pos=1;
		else if(cnt2>n/2) pos=2;
		else if(cnt3>n/2) pos=3;
		if(pos==-1) cout<<ans;
		else{
			for(int i=1;i<=n;i++){
				if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][pos]){
					int maxx=-200000;
					for(int j=1;j<=3;j++){
						if(j!=pos)
							maxx=max(maxx,a[i][j]-a[i][pos]);
					}
					b[++cnt_b]=maxx;
				}
			}
			sort(b+1,b+1+cnt_b);
			//for(int i=1;i<=cnt_b;i++) cout<<b[i];
			//cout<<endl;
			//cout<<ans<<" ";
			for(int i=cnt_b;i>=n/2+1;i--){
				ans+=b[i];
				
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}
