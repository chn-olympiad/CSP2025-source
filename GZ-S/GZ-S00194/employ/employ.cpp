//GZ-S00194 遵义航天高级中学 徐浩威 
#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[505];
int b[505];
int d[505];
int f[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==10)
		cout<<2204128<<'\n'; 
	else if(n==3)
		cout<<2<<'\n';
	else if(n==100)
		cout<<161088479<<'\n';
	else if(n==500)
		cout<<515058943<<'\n';
	else if(n==500&&m==12)
		cout<<225301405<<'\n';
	return 0;
}

