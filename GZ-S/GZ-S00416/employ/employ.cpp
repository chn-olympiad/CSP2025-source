//GZ-S00416 谭怡鹏 恒升高级中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	long long o=0;
	for(int i=m;i>=1;i--){
		long long s=1;
		for(int x=n;x>=i;x--)s*=x;
		o+=s;
	}
	cout<<o;
	return 0;
}
