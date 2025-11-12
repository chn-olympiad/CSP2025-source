//GZ-S00285 贵阳市第一中学 樊墨涵 
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		ans*=i;
	}
	cout <<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
