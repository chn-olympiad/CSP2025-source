//GZ-S00082 贵州师范大学云岩实验中学 吴倬然
#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,m,a[506],ans,c;
string str;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m>>str;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=2; i<=m; i++){
		ans=(ans*i)%MOD;
	}
	cout<<ans;
return 0;
}

