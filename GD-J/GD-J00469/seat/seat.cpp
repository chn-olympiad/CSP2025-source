#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	
	int n,m,id,now=0;
	cin>>n>>m;
	vector<int> a(n*m);
	cin>>a[0];
	id=a[0];
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	for(int j=1;j<=m;j++) {
		if(j%2==1) {
			for(int i=1;i<=n;i++) {			
				if(id==a[now]) {
					cout<<j<<' '<<i;
					return 0;
				}
				now++;
			}
		}
		else {
			for(int i=n;i>=1;i--) {
				if(id==a[now]) {
					cout<<j<<' '<<i;
					return 0;
				}
				now++;
			}
		}
	}
}
