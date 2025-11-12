#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[110];
int a[15][15];
int t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	t=s[1];
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++){
		int r=i%n;
		if(r==0)
			r=n;
		int o=(i-1)/n+1;
		int w=o%2;
		if(w==1)
			a[r][o]=s[n*m-i+1];
		else
			a[n-r+1][o]=s[n*m-i+1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
