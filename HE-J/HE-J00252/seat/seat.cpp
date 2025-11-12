#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	return 0;
}
