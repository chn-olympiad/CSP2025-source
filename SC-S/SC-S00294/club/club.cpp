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
ll ans,lim,a[100010][7],m;
void bl(ll n,ll sum,ll &x,ll &y,ll &z){
	if(n==lim){
		ans=max(ans,sum);
		return ;
	}
	if(a[lim][4]-a[n][4]+sum<ans)return ;
	x++;
	if(x<=m)bl(n+1,sum+a[n+1][1],x,y,z);
	x--;
	y++;
	if(y<=m)bl(n+1,sum+a[n+1][2],x,y,z);
	y--;
	z++;
	if(z<=m)bl(n+1,sum+a[n+1][3],x,y,z);
	z--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=in();
	while(t--){
		ans=0;
		lim=in();
		m=lim/2;
		for(ll i=1;i<=lim;i++){
			a[i][1]=in();
			a[i][2]=in();
			a[i][3]=in();
			a[i][4]=max(a[i][1],max(a[i][2],a[i][3]));
			a[i][4]+=a[i-1][4];
		}
		ll x=0,y=0,z=0;
		bl(0,0,x,y,z);
		out(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}