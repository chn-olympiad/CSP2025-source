#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=' ';
	int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum;
}
int T,n;
struct node{
	int a,b,c;
	int wd;
	void readin(){
		a=read();
		b=read();
		c=read();
		wd=max(abs(a-b),max(abs(a-c),abs(b-c)));
	}
}su[100005];
bool cmp(node a,node b){
	return a.wd>b.wd;
}
mt19937 srd(time(0));
//20pts 3^n
int ans;
void dfs(int id,int ra,int rb,int rc,int sum){
	if(id>n){
		ans=max(ans,sum);
		return;
	}
	if(ra<n/2)dfs(id+1,ra+1,rb,rc,sum+su[id].a);
	if(rb<n/2)dfs(id+1,ra,rb+1,rc,sum+su[id].b);
	if(rc<n/2)dfs(id+1,ra,rb,rc+1,sum+su[id].c);
	return;
}
//
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			su[i].readin();
		}
		if(n<=16){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		sort(su+1,su+1+n,cmp);
		int tcs=18000000/n,ans=0,mxd=n/2;;
		while(tcs--){
			int cnt_brokena=0,cnt_brokenb=0,cnt_brokenc=0;
			int sum=0;
			for(int i=1;i<=n;++i){
				int sra=su[i].a*20;
				int srb=su[i].b*20;
				int src=su[i].c*20;
				int res=srd()%(sra+srb+src);
				if(res<sra&&cnt_brokena<mxd){
					sum+=su[i].a;
					++cnt_brokena;
				}
				else if(res<sra+srb&&cnt_brokenb<mxd){
					sum+=su[i].b;
					++cnt_brokenb;
				}
				else if(cnt_brokenc<mxd){
					sum+=su[i].c;
					++cnt_brokenc;
				}
				else if(cnt_brokenb<mxd){
					sum+=su[i].b;
					++cnt_brokenb;
				}
				else{
					sum+=su[i].a;
					++cnt_brokena;
				}
			}
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
} 
/*
Do not know the correct soultion.
Used rand()

Uid:753204 mywzj_mo
bits\stdc++.h
//freopen
freeopen
freopen("club.out","r",stdin)
freopen("club.in","w",stdout)
int mian(){
cnt_broken=4;

The dance of fire and ice
The dance line
Minecraft
Phgrious
Theresmore
Plant vs Zombie
Five night at Freddy's(1,2,3,4,sister location,???,
ulimate custom night,Help wanted(1,2),???,the secret of ???,
into the pit)
-The joy of create
Changed
Changed-special
Undertale
Pobby's gametime(1,2,3,4)

Goodbye.Everyone 20+16+30+8=74.
Why this year too difficult!!!
 
My friend:XDB(Baned User),PuShuai(Not oier).
------They ask me to write them into the code.
*/
