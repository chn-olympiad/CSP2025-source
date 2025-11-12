#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	int r=a[1];
	if(n*m==1) cout<<1<<" "<<1;
	return 0;
}