#include<bits/stdc++.h>
using namespace std;
int s[1005],n,m,re,x;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> s[i];
	}
	re=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m;++i){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				if(s[n*(i-1)+j]==re){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;--j){
				if(s[n*(i-1)+n-j+1]==re){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
