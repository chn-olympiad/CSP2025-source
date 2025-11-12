#include<bits/stdc++.h>

using namespace std;

int a[1007],n,m;

bool cmp(int b,int c){return b > c;}

int main(){freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int tar = a[1];
	sort(a+1,a+1+n*m,cmp);
	int r = 1,c = 1,cnt = 1,p = 1;
	while(r * c<=n * m){
		if(a[cnt] == tar){
			break;
		}
		cnt++;
		r+=p;
		if(r == n+1){
			c++,p = -p;
			r = n;
		}else if(r == 0){
			c++,p = -p;
			r = 1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
/*
4 3
95 100 99 98 97 96 94 93 92 91 90 89

*/
