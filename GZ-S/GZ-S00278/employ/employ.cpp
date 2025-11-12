//GZ-S00278 毕节市七星关东辰实验学校 杨鹏鸣 
#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long ans=1,n,m;
long long c[N],mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
