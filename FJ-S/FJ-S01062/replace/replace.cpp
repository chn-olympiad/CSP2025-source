#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	n=read();
	q=read();
	for(ll i=1;i<=q;++i){
		write(0);
		putchar('\n');
	}
	return 0;
}
/*
Ô¸´ËÐÐ ÖÕµÖÈºÐÇ 
*/
