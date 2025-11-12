#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
#define mod 998244353
int n,m,ans;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}return x*f;
}
void write(int x){
	static int st[40],top=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x){
		st[++top]=x%10;
		x/=10;
	}if(top==0) st[++top]=0;
	while(top) putchar(st[top--]);
	return ;
}
bool used[N];
struct node{
	int id,day;
	bool operator < (const node &e) const{
	   return e.day <day;
	}
}a[N];
node b[N];
string s;
vector<int>st;
void solve(int day,int sum,int nsum){
	if(sum>=m){
		int cnt=1;
		for(int i=n;i>=day;i--){
			cnt=(cnt*(n-i+1))%mod;
		}
		ans=(ans+cnt)%mod;
		return ;
	}
	if(day>n) return ;
	if(s[day-1]=='1'){
		for(int i=0;i<st.size();i++){
			if(used[st[i]]) continue;
			used[st[i]]=1;
			if(a[st[i]].day >nsum){
				solve(day+1,sum+1,nsum);
			}else solve(day+1,sum,nsum+1);
			used[st[i]]=0;
		}
	}else {
		for(int i=0;i<st.size();i++){
			if(used[st[i]]) continue; 
			used[st[i]]=1;
			solve(day+1,sum,nsum+1);
			used[st[i]]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
   cin>>s;
	for(int i=1;i<=n;i++) {
		a[i].day =read();
		st.push_back(i);
	}
	solve(1,0,0);
	cout<<ans;
	return 0;
}
