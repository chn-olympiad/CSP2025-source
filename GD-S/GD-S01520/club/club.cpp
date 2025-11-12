#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
struct club{
	long long x,y,z;
}a[N];
long long maxn,n,c1,c2,c3;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		maxn=0;
		c1=c2=c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			long long oooo=max({a[i].x,a[i].y,a[i].z});
			if(c1<n/2&&oooo==a[i].x){
				c1++;
				maxn+=a[i].x;
			}
			else if(c2<n/2&&oooo==a[i].y){
				c2++;
				maxn+=a[i].y;
			}
			else if(c3<n/2){
				c3++;
				maxn+=a[i].z;
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
} 
