#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[110],a,seat[11][11];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++) cin>>num[i];
	a=num[1];
	sort(num+1,num+n*m+1,cmp);
	int cnt=1;
	for(int i = 1; i<=m; i++) {
		for(int j = (i&1?1:n); (i&1?j<=n:j>=1); j+=pow(-1,1-(i&1))) {
			seat[j][i]=num[cnt++];
			if(seat[j][i]==a){
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
