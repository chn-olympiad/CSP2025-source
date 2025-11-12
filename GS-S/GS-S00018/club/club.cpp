#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		int n,D=0;
		cin>>n;
		int a[n][3],c[3];
		c[1]=0;
		c[2]=0;
		c[3]=0;
		for(int j=1; j<=n; j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
	}
		if(a[1][2]==0&&a[1][3]==0){
		int N=1e5+1;
		int a[N];
		int h=0;
		for(int i=1;i<=n;i++){
			
			h+=a[i];
			
		}cout<<h/2;
		}
}
	return 0;
}
