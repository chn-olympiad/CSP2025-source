//GZ-S000173 中央民族大学附属中学贵阳学校 张诗苑
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s; 
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		ans=(1LL*ans*n)%998244353;
	}
	cout<<ans;
	return 0;
}  
