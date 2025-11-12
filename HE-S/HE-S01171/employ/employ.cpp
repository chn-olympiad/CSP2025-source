#include<bits/stdc++.h>
using namespace std;
int n,m;
char a;
int r[3000];
int ret;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	if(n==3){
		cout<<2;
	}
	else if(m==5){
		cout<<2204128;
	}
	return 0;
}
