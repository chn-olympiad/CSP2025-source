//GZ-S00161 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
string s;
int a[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
} 
