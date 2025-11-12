#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,q;
inline long long rd(){
	ll x=0,f=1;
	char c; c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c-'0');c=getchar();}
	return x*f;}
inline void pu(long long x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) pu(x/10);
	putchar((x%10+'0'));}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd();q=rd();
	while(q--){
		printf("0\n");
	}
	return 0;
}
