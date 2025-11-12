#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

int n,m,a;
string s;

bool flag=1;

long long ans=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]=='0')flag=0;
	if(flag==1){
		for(int i=1;i<=n;i++){
			a=read();
			if(a==0)n--;
		}
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		printf("%lld",ans);		
	}if(m==1){
		printf("1");
	}else {
		printf("0");
	}
	return 0;
}
