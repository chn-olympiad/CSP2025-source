#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll in(){
	ll k=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c^48);
		c=getchar();
	}
	return f?k:-k;
}
void out(ll x){
	ll pos=0;
	char buf[20];
	if(x<0){
		x=-x;
		putchar('-');
	}
	buf[pos++]=x%10^48;
	x/=10;
	while(x){
		buf[pos++]=x%10^48;
		x/=10;
	}
	while(pos){
		putchar(buf[--pos]);
	}
}
void outel(ll x){
	out(x);
	putchar('\n');
}
char s[1000010];
ll num[15];
bool pz=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(ll i=1;s[i];i++){
		if(s[i]>='0'&&s[i]<='9')num[s[i]^48]++;
	}
	for(ll i=9;i>=1;i--){
		for(ll j=1;j<=num[i];j++){
			putchar(i^48);
		}
		if(num[i])pz=0;
	}
	if(pz){
		putchar('0');
	}
	else {
		for(ll j=1;j<=num[0];j++){
			putchar('0');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}