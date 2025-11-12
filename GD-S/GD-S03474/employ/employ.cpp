#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=25;
int n,m,a[N],b[N],r=0;
char z[N];
signed main(){
#ifndef XYZ
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>z+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	do{
		int s=0,t=0;
		for(int i=1;i<=n;i++){
			int p=b[i];
			if(t>=a[p]){
				++t;
				continue;
			}
			if(z[i]&1)++s;
			else ++t;
		}
		if(s>=m)++r;
	}while(next_permutation(b+1,b+n+1));
	cout<<r;
	return 0;
}


