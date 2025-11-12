#include <bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int Maxn=1e5+27;
struct node
{
	int a,b,c,summer,best,better;
}mp[Maxn];
bool cmp(node a,node b) {
	return a.summer>b.summer;
}
int vis[4],a[4];
int n,t;
ll ans=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		ans=0;
		ffor(i,1,3) vis[i]=0;
		ffor(i,1,n) {
			ffor(j,1,3) cin>>a[j];
			mp[i].a=a[1],mp[i].b=a[2],mp[i].c=a[3];
			sort(a+1,a+4);
			mp[i].summer=a[3]-a[2];
			mp[i].best=a[3];
			mp[i].better=a[2];
		}
		sort(mp+1,mp+1+n,cmp);
		ffor(i,1,n) {
			a[1]=mp[i].a,a[2]=mp[i].b,a[3]=mp[i].c;
			//cout<<a[1]<<a[2]<<a[3]<<' '<<mp[i].best<<mp[i].better<<'\n';
			ffor(j,1,3) {
				if (a[j]==mp[i].best) {
					if (vis[j]==n/2) {
						ffor(k,1,3) {
							if (a[k]==mp[i].better&&k!=j) {
								ans+=a[k];
								vis[k]++;
								break;
							}
						}
					}
					else {
						ans+=a[j];
						vis[j]++;
					}
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
//freopen
//g++ -std=c++14 -O2 club.cpp -o club
//我终于切掉 t1 了 呜呜呜
/*
再见 oi。
2025-11.01
Luogu uid:1273409
*/