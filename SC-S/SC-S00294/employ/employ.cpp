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
		putchar('-');
		x=-x;
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
ll sum[510],n,m,num[510],ans;
char s[510];
ll bl(ll lim,ll *num,ll js){
	if(lim==n){
		if(js>=m)return 1;
	}
	ll an=0;
	for(ll i=0;i<=500;i++){
		if(num[i]){
			num[i]--;
			if(s[lim+1]=='1'){
				if(sum[lim+1]>i)an+=bl(lim+1,num,js)*(num[i]+1);
				else an+=bl(lim+1,num,js+1)*(num[i]+1);
			}
			else an+=bl(lim+1,num,js)*(num[i]+1);
			num[i]++;
		}
	}
	return an%=998244353;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();m=in();
	scanf("%s",s+1);
	sum[0]=1;
	for(ll i=1;s[i];i++){
		sum[i]=sum[i-1];
		if(s[i]=='0')sum[i]++;
	}
	for(ll i=1;i<=n;i++){
		num[in()]++;
	}
	out(bl(0,num,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}