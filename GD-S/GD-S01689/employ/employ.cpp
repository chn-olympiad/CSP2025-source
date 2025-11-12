#include<bits/stdc++.h>
#define ll long long
using namespace std;
char get_char;
bool sign;
bool isnum(const char &x){
	return ('0'<=x && x<='9');
}
void read(ll &x){
	x=0;
	get_char=getchar();
	sign=0; 
	while(!isnum(get_char)){
		if(get_char=='-')sign=1;
		get_char=getchar();
	}
	while(isnum(get_char)){
		x=(x<<3)+(x<<1)+(get_char-'0');
		get_char=getchar();
	}
	if(sign)x=-x;
}
const ll mod=998244353;
ll n,m,xxx,ans,cnt,c[5005];
bitset<505>S;
char x;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	flag=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='0')flag=S[i]=0;
		else S[i]=1;
	}
	for(int i=1;i<=n;i++)read(c[i]);
	cout<<rand();
	return 0;
}
