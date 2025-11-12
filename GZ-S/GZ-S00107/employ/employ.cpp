//GZ-S00107 贵阳市第一中学 周晓凡 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cnt*=i;
		cnt%=998244353;
	}
	cout<<(cnt%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
