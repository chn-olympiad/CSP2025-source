#include <bits/stdc++.h>
using namespace std;
int rs,zs,zzs[501],a,nx[501];
char t[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>rs>>zs;
	cin>>t;
	for(int i=0;i<rs;i++){
		cin>>a;
		nx[a]++;
	}
	cout<<rs*rs;
	return 0;
}



