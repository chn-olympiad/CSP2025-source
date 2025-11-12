#include<bits/stdc++.h>
using u64=unsigned long long;
using namespace std;
namespace IO{
	void read(int &x){
		short f=1;x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
		x*=f;
		return;
	}
	void out_(int x){
		if(x>9) out_(x/10);
		putchar(x%10+'0');
		return;
	}
	void out(int x){
		if(x<0) putchar('-'),x=-x;
		out_(x);putchar(' ');
		return;
	}
}using namespace IO;
char st;
const int N=2e5+5,B=231,R=114514123;
int n,q,pre[N],suf[N];
string s1[N],s2[N];
string t1[N],t2[N];
unordered_map<u64,int>mp;
char ed;
void file(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return;
}
void get(string &a,string &b){
	int len=(int)a.size();
	u64 res1=0,res2=0;
	for(int i=0;i<len;i++) res1=res1*B+a[i];
	for(int i=0;i<len;i++) res2=res2*B+b[i];
	u64 hsh=res1*R+res2;
	mp[hsh]++; 
	return;
}
void solve(string &a,string &b){
	int len=(int)a.size();
	for(int i=0;i<len;i++){
		if(i==0) pre[i]=(a[i]==b[i]);
		else pre[i]=((a[i]==b[i])&pre[i-1]);
	}
	for(int i=len-1;i>=0;i--){
		if(i==len-1) suf[i]=(a[i]==b[i]);
		else suf[i]=((a[i]==b[i])&suf[i+1]);
	}
	long long res=0;
	for(int i=0;i<len;i++){
		u64 res1=0,res2=0;
		if(i&&pre[i-1]==0) break; 
		for(int j=i;j<len;j++){
			res1=res1*B+a[j];
			res2=res2*B+b[j];
			if(j==len-1||suf[j+1]) res+=mp[res1*R+res2];
		}
	}
	printf("%lld\n",res);
	return;
}
bool ins(string &a){
	int len=a.size();
	int res1=0,res2=0;
	for(int i=0;i<len;i++){
		if(a[i]=='a') res1++;
		if(a[i]=='b') res2++;
	}
	return !(res1==len-1&&res2==1);
}
int getid(string &a){
	int len=a.size();
	for(int i=0;i<len;i++)
		if(a[i]=='b') return i;
	return 0;
}
bool Sub(){
	for(int i=1;i<=n;i++){
		if(ins(s1[i])) return false;
		if(ins(s2[i])) return false;
	}
	for(int i=1;i<=q;i++){
		if(ins(t1[i])) return false;
		if(ins(t2[i])) return false;
	}
	return true;
}
vector<pair<int,int>>tong[4*N];
int main(){
	file();
	read(n),read(q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		get(s1[i],s2[i]);
	}
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	if(Sub()){
		for(int i=1;i<=n;i++){
			int tmp1=getid(s1[i]),tmp2=getid(s2[i]);
			tong[tmp1-tmp2+N].push_back(pair<int,int>{s1[i].size()-tmp1,tmp1});
		}
		for(int i=1;i<=q;i++){
			int tmp=getid(t1[i])-getid(t2[i]),tmp1=getid(t1[i]);
			int res=0,k=t1[i].size()-getid(t1[i]);
			for(pair<int,int> u:tong[tmp+N])
				if(k>=u.first&&tmp1>=u.second) res++;
			printf("%d\n",res);
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
		solve(t1[i],t2[i]);
	return 0;
}

