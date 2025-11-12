#include<bits/stdc++.h>
using namespace std;
struct data{
	int a,b,c,id,mx,mn,mid;
}s[100010];
int t;
int n;
bool cmpabc5(data ma,data mi){
	return ma.mx-ma.mid>mi.mx-mi.mid;
}
int cnta,cntb,cntc;
int solve(){
	cnta=cntb=cntc=0;
	int res=0;
	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",s[i].mn,s[i].mid,s[i].mx);
		if(s[i].a>s[i].b&&s[i].a>s[i].c){
			if(cnta<n/2)cnta++,res+=s[i].a;
			else{
				if(s[i].b>s[i].c)
					res+=s[i].b,cntb++;
				else res+=s[i].c,cntc++;
			}
		}
		else if(s[i].b>s[i].a&&s[i].b>s[i].c){
			if(cntb<n/2)cntb++,res+=s[i].b;
			else{
				if(s[i].a>s[i].c)
					res+=s[i].a,cnta++;
				else res+=s[i].c,cntc++;
			}
		}
		else if(s[i].c>s[i].a&&s[i].c>s[i].b){
			if(cntc<n/2)cntc++,res+=s[i].c;
			else{
				if(s[i].a>s[i].b)
					res+=s[i].a,cnta++;
				else res+=s[i].b,cntb++;
			}
		}
		else{
			res+=s[i].mx;
		}
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].mx=max(s[i].a,max(s[i].b,s[i].c));
			s[i].mn=min(s[i].a,min(s[i].b,s[i].c));
			s[i].mid=s[i].a+s[i].b+s[i].c-s[i].mx-s[i].mn;
			s[i].id=i;
		}
		cnta=cntb=cntc=0;
		int ans=0;
		sort(s+1,s+n+1,cmpabc5);
		ans=solve();
		printf("%d\n",ans);
	}
	return 0;
}
