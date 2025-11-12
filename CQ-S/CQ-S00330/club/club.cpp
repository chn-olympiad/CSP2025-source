#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define __int __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define psb push_back
#define lbd lower_bound
#define pbd upper_bound
#define endl '\n'

const int mx=2e5+5;
int t,n,c[3];
pair<int,pii>a[mx];
ll s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s=0;
		c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++){
			pii x[3];
			for(int j=0;j<3;j++){
				cin>>x[j].F;
				x[j].S=j;
			}
			sort(x,x+3);
			a[i]={x[2].F-x[1].F,{x[2].S,x[1].S}};
			s+=x[1].F;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>0;i--){
			if(c[a[i].S.F]<n/2){
				c[a[i].S.F]++;
				s+=a[i].F;
			}else c[a[i].S.S]++;
		}
		cout<<s<<endl;
	}
	return 0;
}
