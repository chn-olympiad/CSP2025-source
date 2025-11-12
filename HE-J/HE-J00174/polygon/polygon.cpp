#include<bits/stdc++.h>
using namespace std;
long long read();
void write(long long a);
long long n,a[5005],ans,mod=998244353,mal=-10,now,c;
void bs(int now,long long ma,int su,long long he){
	if(now>n){
		if(su>=3&&he>ma*2){
			//cout<<now<<" "<<he<<endl;;
			ans=(ans+1)%mod;
		}
	}
	else{
		bs(now+1,ma,su,he);
		bs(now+1,max(ma,a[now]),su+1,he+a[now]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		mal=max(mal,a[i]);
	}
	//cout<<mal<<endl;
	if(mal==1){
		now=n*(n-1)*(n-2)%mod;
		c=6;
		ans+=(now/c);
		for(int i=4;i<=n;i++){
			now=now*(n-i+1)%mod;
			c=c*i%mod;
			ans=(ans+now/c)%mod;
		}
		write(ans);
	}
	else{
		bs(2,a[1],1,a[1]);
		bs(2,0,0,0);
		write(ans);
	}
	return 0;
}
long long read(){
	long long f=1,now=0;
	char c;
	c=getchar();
	while('0'>c||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		now=(now<<3)+(now<<1)+c-'0';
		c=getchar();
	}
	return now*f;
}
void write(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>=10) write(a/10);
	putchar(a%10+'0');
}
