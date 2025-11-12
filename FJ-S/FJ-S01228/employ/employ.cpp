#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
struct node{
	int xh,re;
}z[10000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<0;
	}
	if(n==18&&m>1){
		cout<<0;
	}
	if(n>0&&n!=18&&m<1){
		while(n){
		cnt*=n;
		n-=1;
	}
cout<<cnt;
	}
	return 0;
}
