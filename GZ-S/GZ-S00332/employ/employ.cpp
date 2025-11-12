//GZ-S00332 贵州省实验中学 王满霖
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	int n,m;cin>>n>>m;
	int sum=1;
	for(int i=m,i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum; 
	return 0;
} 
