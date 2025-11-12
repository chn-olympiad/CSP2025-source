#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n;
struct node{
	ll a,b,c,favor,sfavor,tfavor,num,num2,num3;
}s[100010];
bool cmp(node x,node y){
	return (x.favor==y.favor?x.num>y.num:x.favor<y.favor);
}
bool cmp1(node x,node y){
	return x.num>y.num;
}
ll check(ll x,ll y){
	if(x!=1&&y!=1) return 1;
	else if(x!=2&&y!=2) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll ca=0,cb=0,cc=0,ans=0;
		bool A=true;
		bool B=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].c!=0||s[i].b!=0) A=false;
			if(s[i].c>s[i].a&&s[i].c>s[i].b) s[i].favor=3;
			else if(s[i].b>s[i].a&&s[i].b>s[i].c) s[i].favor=2;
			else s[i].favor=1;
			s[i].num=max({s[i].a,s[i].b,s[i].c});
			s[i].num3=min({s[i].a,s[i].b,s[i].c});
			if(s[i].c<s[i].a&&s[i].c>s[i].b||s[i].c>s[i].a&&s[i].c<s[i].b){
				s[i].num2=s[i].c;
				s[i].sfavor=3;
			}
			else if(s[i].b<s[i].a&&s[i].b>s[i].c||s[i].b>s[i].a&&s[i].b<s[i].c){
				s[i].num2=s[i].b;
				s[i].sfavor=2;
			}
			else{
				s[i].num2=s[i].a;
				s[i].sfavor=1;
			}
			s[i].tfavor=check(s[i].favor,s[i].sfavor);
		}
		if(A){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2&&s[i].favor==1;i++) ans+=s[i].num;
		}
		else{
			sort(s+1,s+n+1,cmp1);
			ll ms[4]={0};
			for(int i=1;i<=n;i++){
				ll t=s[i].favor;
//				if(ms[t]>n/2){
//					if(s[i].sfavor)
//					t=s[i].sfavor;
//				}
//				if(t==2&&mb>n/2) t=s[i].sfavor;
				if(ms[t]>n/2) t=s[i].sfavor;
				else if(ms[t]>n/2) t=s[i].tfavor;
				ms[t]++;
				ans+=s[i].num;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
