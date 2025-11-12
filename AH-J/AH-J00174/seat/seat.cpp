#include<bits/stdc++.h>
#define rd read()
#define el putchar('\n')
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll x=0,flag=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			flag=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const ll MAXN=15,inf=1e18,mod=1e9+7;
ll n,m,r,cnt;
ll a[MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=rd,m=rd;
	r=rd;
	for(int i=2;i<=n*m;i++){
		if(rd>r){
			cnt++;
		}
	}
	ll i=1,x=1,y=1;
	while(i<=cnt){
		i++;
		if(y%2==1){
			if(x<n){
				x++;
			}else{
				y++;
			}
		}else{
			if(x>1){
				x--;
			}else{
				y++;
			}
		}
	}
	write(y);putchar(' ');write(x);
	return 0;
}
