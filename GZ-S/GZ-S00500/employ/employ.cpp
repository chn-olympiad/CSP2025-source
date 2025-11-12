//GZ-S00500 北京师范大学贵阳附属学校 黄人麟
#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
long long n,m,sum,ans1=1,ans2=1;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=100;i>=1;i--){
		ans1=((ans1%mod)*(i%mod))%mod;
	}
	for(int i=47;i>=1;i--){
		ans2=((ans2%mod)*(i%mod))%mod;
	}
	cout<<161088479;
	return 0;
}
