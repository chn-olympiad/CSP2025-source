#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
} 
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=1e6+10;
ll sum[15];
char c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	ll n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if('0'<=c[i]&&c[i]<='9') sum[c[i]-'0']++;
	}
	for(int i=9;i>=0;i--) while(sum[i]--) write(i);
	return 0;
}
