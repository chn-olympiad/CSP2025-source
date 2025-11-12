#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t, n;
int px, py, pz;
struct per{
	int fav;
	int x, y, z;
}a[N];
bool cmp(per a, per b){return a.x>b.x;}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		ll ans=0;
		px=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;		
		sort(a+1, a+n+1, cmp);		
		for(int i=1;i<=n;i++){
			if(px<n/2){
				ans+=a[i].x;
				px++;
			}
		}			
		cout<<ans<<endl;
	}
	return 0;
}
