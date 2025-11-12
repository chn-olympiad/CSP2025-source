#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N=100005;
ll t,n,man[3],a[N][3],cha[N][3],ans;
int main() {
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>t;
	for(ll popo=0; popo<t; popo++) {
		memset(a,0,sizeof(a)),memset(man,0,sizeof(man)),memset(cha,0,sizeof(cha)),ans=0;
		cin>>n;
		for(ll i=0; i<n; i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ll j=-1,k=-1;
			if(a[i][0]>a[i][1]) {
				if(a[i][0]>a[i][2]) {
					j=0;
					if(a[i][1]>a[i][2]) {
						k=1;
					} else {
						k=2;
					}
				} else {
					j=2;
					k=0;
				}
			} else {
				if(a[i][1]>a[i][2]) {
					j=1;
					if(a[i][0]>a[i][2]) {
						k=0;
					} else {
						k=2;
					}
				} else {
					j=2;
					k=1;
				}
			}
			if(j==-1||k==-1) {
				cout<<"ERROR!";
			}
			ans+=a[i][j];
			man[j]+=1;
			cha[a[i][j]-a[i][k]][j]+=1;
		}
		for(ll i=0; i<3; i++) {
			if(man[i]>n/2) {
				for(ll point=0; man[i]>n/2;) {
					if(cha[point][i]==0) {
						point+=1;
						continue;
					}
					ans-=point;
					cha[point][i]-=1;
					man[i]-=1;
				}
			}
		}
		cout<<ans;
		if(popo!=t-1) {
			cout<<endl;
		}
	}
	return 0;
}
