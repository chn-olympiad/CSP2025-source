#include<bits/stdc++.h> 
using namespace std;
int n,m,a[110],p,cnt;
bool cmp(int a1,int a2) {
	return a1>a2;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++) {
		if(i%2==1) {
			for(int j=1;j<=m;j++) {
				if(a[++cnt]==p) {
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		} else {
			for(int j=m;j>=1;j--) {
				if(a[++cnt]==p) {
					cout<<i<<" "<<j<<"\n";
					return 0;
				}				
			}			
		}
	}
	return 0;
} 
