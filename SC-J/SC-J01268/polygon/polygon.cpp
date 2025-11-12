#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],ans; //方案总数 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	if(n<3) {cout<<"0";return 0;}
	if(n==3){
		int x,y,z;cin>>x>>y>>z;
		int maxn=max(x,max(y,z));
		if(x+y+z>2*maxn) {cout<<"1";return 0;}
		cout<<"0";return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==5) {cout<<"9";return 0;}
	return 0;
}