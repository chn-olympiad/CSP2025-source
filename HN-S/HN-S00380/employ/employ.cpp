#include<bits/stdc++.h>
using namespace std;
#define twa 998244353
int n,m,a[501],qp[501],t,fs; string st;
long long s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d\n",&n,&m);
	cin>>st;
	for(int i=0;st[i];i++)
	  if(st[i]=='1') fs++;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		qp[i]=i;
	}
	if(fs==n){
		printf("%lld",((n*(n+1)/2)%twa));
		return 0;
	}
	do{
		t=0;
		for(int i=0;st[i];i++)
		  if(t>=a[qp[i+1]] || st[i]=='0')
			t++;
		if(n-t>=m) s=(s+1)%twa;
	}while(next_permutation(qp+1,qp+1+n));
	printf("%lld",s%twa);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
