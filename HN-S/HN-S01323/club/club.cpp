#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int b[1000],c[1000],d[1000];
	while(a--){
		int n;
		cin>>n;
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			int m,m2,m1;
			cin>>m>>m1>>m2;
			int o = max(m,m1);
			int o1 = max(o,m2);
			cnt = cnt +o1;
		}
		cout<<cnt;
	}
	return 0;
}
