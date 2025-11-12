//为什么要攀登？因为山就在那里。 
#include<bits/stdc++.h>
#define mrx 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
inline int read(){
	int num=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar(); 
	}
	return num*flag;
}
char wshthxdsdg[40];
inline void write(int num){
	int flag=0;
	if(!num) return putchar('0'),void();
	if(num<0) putchar('-'),num=-num;
	while(num){
		wshthxdsdg[++flag]=((num%10)^48);
		num/=10;
	}
	for(int i=flag;i;i--) putchar(wshthxdsdg[i]);
}
inline void out(int num){
	write(num);
	putchar(' ');
}
inline void print(int num){
	write(num);
	putchar('\n');
}
inline int ksm(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
int _;
int n;
int a[100010][5];
int club[5][100010];
int num[5];
int ans;
priority_queue<int,vector<int>,greater<int> > q;
int check(int id){
	if(a[id][1]>=a[id][2]&&a[id][1]>=a[id][3]) return 1;
	if(a[id][2]>=a[id][1]&&a[id][2]>=a[id][3]) return 2;
	return 3;
}
int solve(){
	if(num[1]>(n>>1)) return 1;
	if(num[2]>(n>>1)) return 2;
	if(num[3]>(n>>1)) return 3;
	return 0;
}
int min_num(int now,int club_id,int id){
	if(club_id==1) return min(now-a[id][2],now-a[id][3]);
	else if(club_id==2) return min(now-a[id][1],now-a[id][3]);
	else return min(now-a[id][2],now-a[id][1]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_=read();
	while(_--){
		while(!q.empty()) q.pop();
		ans=0;
		num[1]=num[2]=num[3]=0;
		n=read();
		for(int i=1;i<=n;i++) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		for(int i=1;i<=n;i++){
			int id=check(i);
			club[id][++num[id]]=i;
			ans+=a[i][id];
		}
		int sol=solve();
		if(!sol) print(ans);
		else{
			int sum=num[sol]-(n>>1);
			for(int i=1;i<=num[sol];i++){
				int now=a[club[sol][i]][sol];
				q.push(min_num(now,sol,club[sol][i]));
			}
			while(sum--){
				ans-=q.top();
				q.pop();
			}
			print(ans);
		}
	} 
	return 0;
}
/*
15:15 maybe 100pts get
*/
