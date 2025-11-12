#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=2e5+7;
struct node{
	string s1,s2;
	int len;
}a[N],ask[N];
int n,q;
int L1,L2;
namespace sol{
	i64 read(){
		i64 x=0,f=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void Dianaqwq(){
		n=read(),q=read();
		up(i,1,n){
			cin>>a[i].s1>>a[i].s2;
			a[i].len=a[i].s1.length();L1+=a[i].len;
		}
		sort(a+1,a+n+1,[](node x,node y){return x.len<y.len;});
		up(i,1,q){
			cin>>ask[i].s1>>ask[i].s2;
			int len=ask[i].s1.length();
			if(len==(int)ask[i].s2.length()) L2+=len;
		}
		if(L2>=1000000&&q>1){
			while(q--){puts("0");}return;
		}
		up(i,1,q){
			string t1=ask[i].s1,t2=ask[i].s2;
			int len=t1.length();
			if(len!=(int)t2.length()){puts("0");continue;}
			int l=0,r=0;
			up(i,0,len-1) if(t1[i]!=t2[i]){l=i;break;}
			dn(i,len-1,0) if(t1[i]!=t2[i]){r=i;break;}
			i64 ans=0;
			up(i,1,n){
				if(a[i].len<r-l+1) continue;
				int f1=t1.find(a[i].s1),f2=t2.find(a[i].s2);
				if(f1==(int)string::npos||f2==(int)string::npos) continue;
				while(f1!=(int)string::npos&&f2!=(int)string::npos){
					string x=t1.substr(0,f1),z=t1.substr(f1+a[i].len,len-f1-a[i].len);
					if(f1==f2&&x+a[i].s2+z==t2) ans++;
					f1=t1.find(a[i].s1,f1+1),f2=t2.find(a[i].s2,f2+1);
				}
			}
			write(ans),puts("");
		}
	}
}
using namespace sol;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Dianaqwq();
	return 0;
}
