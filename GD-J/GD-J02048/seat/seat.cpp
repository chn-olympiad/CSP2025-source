//T2 Èë»ú-----
/*
*/ 
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 103;
int a[N],r,n,m,pos,i,j;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			cin >> a[++pos];
			if(i==1&&j==1) r = a[pos];
		}
	sort(a+1,a+pos+1,greater<int>());
	i=1;j=1;pos=0;
	while(a[++pos]!=r){
		if(j%2==1){
			if(i==n)
				++j;
			else
				++i;
		}else{
			if(i==1)
				++j;
			else
				--i;
		}
	}cout << j << ' ' << i;
	return 0;
}
