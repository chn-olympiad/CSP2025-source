#include<bits/stdc++.h>
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
#define inf 0x3f3f3f3f
#define int long long
#define il inline
#define push_back pb
#define pii pair<int,int>
#define hh putchar('\n')
#define kg putchar(' ')
#define fir first
#define sec second
#define lowbit ((i)&(-i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
il int read(){
	int num=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=1;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return f?-num:num;
}
il void write(int x){
	if(x<0)putchar('-'),x=-x;
	int stk[50],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	dlp(i,top,1)putchar(stk[i]+'0');
}
#define N 100005
int T;
struct RP{
	int a,b;
	int A,B;
}stu[N];
int n;
int hanser=0;
int cnt[4];
void solve(){
	n=read();
	hanser=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	ulp(i,1,n){
		int a=read(),b=read(),c=read();
		if(a>=b&&a>=c){
			if(b>=c)stu[i]={a,b,1,2};
			else stu[i]={a,c,1,3};
		}
		else if(b>=c&&b>=a){
			if(a>=c)stu[i]={b,a,2,1};
			else stu[i]={b,c,2,3};
		}
		else {
			if(a>=b)stu[i]={c,a,3,1};
			else stu[i]={c,b,3,2};
		} 
	}
	sort(stu+1,stu+n+1,[&](RP x,RP y){
		return x.a-x.b>y.a-y.b;
	});
	ulp(i,1,n){
		if(stu[i].a<stu[i].b)swap(stu[i].a,stu[i].b);
		//write(stu[i].a),kg,write(stu[i].b),hh;
		if(cnt[stu[i].A]<n/2){
			++cnt[stu[i].A];
			hanser+=stu[i].a;
		}
		else if(cnt[stu[i].B]<n/2){
			++cnt[stu[i].B];
			hanser+=stu[i].b;
		} 
	}
	write(hanser),hh;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	solve();
	return 0;
} 
// 35 
//  
