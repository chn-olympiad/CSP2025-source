#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n,m,a[N*N];

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int r=1,c=1;
	for(int i=1;i<=n*m;i++) {
		if(a[i]==x)break;
		if(c%2==0) {
			if(r==1)c++;
			else r--;
		}else{
			if(r==n)c++;
			else r++;
		}
	} 
	cout<<c<<" "<<r;
	return 0;
}
 
