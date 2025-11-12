#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,ans;
bool b[N];
map<pair<int,int>,int>m;
struct node {
	int s,l;
} a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>m[ {i,i}];
		if(m[ {i,i}]==k)a[++cnt].s=1,a[cnt].l=i;
	}
	for(int i=2; i<=n; i++)
		for(int j=1; j+i-1<=n; j++) {
			m[ {j,j+i-1}]=m[ {j,j+i-2}]^m[ {j+i-1,j+i-1}];
			if(m[ {j,j+i-1}]==k)a[++cnt].s=i,a[cnt].l=j;
		}
	for(int i=1; i<=cnt; i++) {
		if(n-ans<a[i].s)break;
		int l=a[i].l,r=a[i].l+a[i].s-1;
		bool flag=0;
		for(int j=l; j<=r; j++) {
			if(b[j]) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			ans++;
			for(int j=l; j<=r; j++)b[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
