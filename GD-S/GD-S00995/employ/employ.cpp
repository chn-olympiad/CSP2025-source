#include<bits/stdc++.h>
using namespace std;
const int N=1000,mod=998244353;
string x;
int c[N],rt=0,ry=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,res=1;
	scanf("%d%d",&n,&m);
	cin>>x;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)rt++;
		res=(res*n)%mod;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		if(c[i]==0)continue;
		if(c[i]<rt)ry++;
	}
	if(n-(ry+rt)>=m)printf("%d",res);
	else if(n-rt<m)printf("0");
	return 0;
}

