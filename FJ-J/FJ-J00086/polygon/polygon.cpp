#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[5005];
const ll mod=998244353;
inline int read(){
	int res=0,fu=1;
	char c;
	while(!isdigit(c)){
		if(c=='-')fu=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=(res<<3)+(res<<1)+(c-48);
		c=getchar();
	}
	return res*fu;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int maxn=max(a[1],max(a[2],a[3]));
		if(sum>maxn*2)printf("1");
		else printf("0");
		return 0;
	}
	return 0;
}

