#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[510],b[510];
char a[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(a+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	int res=0;
	do{
		int gv=0;
		for(int i=1;i<=n;i++){
			if(gv>=c[b[i]]){
				gv++;
			}
			else{
				if(a[i]=='0'){
					gv++;
				}
			}
		}
		if(n-gv>=m){
			res++;
		}
	}
	while(next_permutation(b+1,b+1+n));
	cout<<res<<endl;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

