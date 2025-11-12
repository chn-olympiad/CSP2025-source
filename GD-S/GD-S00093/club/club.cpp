#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,t=1;
	char a;
	while(!isdigit(a=getchar()))t=a=='-'?-1:t;
	do{x=(x<<3)+(x<<1)+(a^48);}while(isdigit(a=getchar()));
	return x*t;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=1e5+5;
int n,cnt1,cnt2,cnt3,s[4][N];
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int T=read();T;T--){
		n=read(),ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			int val1=read(),val2=read(),val3=read();
			if(val1>=val2 and val1>=val3)s[1][++cnt1]=val1-max(val2,val3),ans+=val1;
			else if(val2>=val1 and val2>=val3)s[2][++cnt2]=val2-max(val1,val3),ans+=val2; 
			else if(val3>=val1 and val3>=val2)s[3][++cnt3]=val3-max(val1,val2),ans+=val3; 
		}
		if(cnt1>n/2){
			sort(s[1]+1,s[1]+cnt1+1);
			for(int i=cnt1-n/2;i>=1;i--)ans-=s[1][i];
		}else if(cnt2>n/2){
			sort(s[2]+1,s[2]+cnt2+1);
			for(int i=cnt2-n/2;i>=1;i--)ans-=s[2][i];
		}else{
			sort(s[3]+1,s[3]+cnt3+1);
			for(int i=cnt3-n/2;i>=1;i--)ans-=s[3][i];
		}
		write(ans),putchar('\n');
	}
	return 0;
}
