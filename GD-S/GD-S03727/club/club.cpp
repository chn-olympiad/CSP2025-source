#include<bits/stdc++.h>
using namespace std;
long long t,n,u1,u2,ans,b2[1000010],cnt2;
struct st{
	long long a,b,c,ch;
}s[1000010];
struct st2{
	long long ch1,ch2;
}a1[1000010],b1[1000010];
bool cmp(st x,st y){
	return x.a>y.a;
}
bool cmp2(st x,st y){
	return x.ch>y.ch;
}
bool cmp3(st x,st y){
	return x.b>y.b;
}
int dfs(long long x,long long c1,long long c2,long long c3,long long cnt){
	if(c1+c2+c3>n||c1>n/2||c2>n/2||c3>n/2||x>n) return 0;
	if(c1+c2+c3==n){
		ans=max(ans,cnt);
		return 0;
	}
	if(x==n){
		ans=max(ans,cnt);
		return 0;
	}
	if (c1+1<=n/2) dfs(x+1,c1+1,c2,c3,cnt+s[x+1].a);
	if (c2+1<=n/2) dfs(x+1,c1,c2+1,c3,cnt+s[x+1].b);
	if (c3+1<=n/2) dfs(x+1,c1,c2,c3+1,cnt+s[x+1].c);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		u1=1,u2=1,ans=0,cnt2=0;
		cin>>n;
		memset(s,0,sizeof(s)),memset(b2,0,sizeof(b2));
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].ch=s[i].a-s[i].b;
			if(s[i].b!=0){
				u1=0;
			}
			if(s[i].c!=0){
				u1=0,u2=0;
			}
		}
		if(u1==1){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a;
			}
		}
		else if(u2==1){
			for(int i=1;i<=n;i++){
				a1[i].ch1=s[i].a-s[i].b;
				a1[i].ch2=s[i].b-s[i].a;
			}
			
		}
		else{
			dfs(0,0,0,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
