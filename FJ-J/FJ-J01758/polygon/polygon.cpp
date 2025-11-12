#include<bits/stdc++.h>
using namespace std;
long long rp=998244353,sum=0;
int n,a[5001],f[5001]={};
void dfs(int x,int s,int awa){
	if (s==x){
		int su=0,ma=-114514;
		for (int i=1;i<=n;i++){
			su+=f[i]*a[i];
			ma=max(ma,f[i]*a[i]);
		}
		if (su>ma*2) sum=(sum+1)%rp;
	}
	for (int i=awa+1;i<=n;i++){
		if (f[i]==1) continue;
		f[i]=1;
		dfs(x,s+1,i);
		f[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=3;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
many test not clean
parent cry two cry eyewater(
ten years OI one chang empty
dont use long long meet grandgrandgrandgrandgrandgrandgrandgrandgrandparent(
luogu is so delicious(
i taoyan xor QAQ T3 is so hard that i need use DEV-C--
rp++
rp--
rp++-
rp--+
ju li csp hai you -1 tian!
i want eat 11451419198101145141919810 chocolates!!!!!!!!!!!
rp+=inf
rprprprprprprprprprprprrprprprprprprrprprprp
             ___                                  luogu.me
{403 error}=|___|===>                             luogu.com.cn
                                                  lglg.top
*/
