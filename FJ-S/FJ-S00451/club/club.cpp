#include <bits/stdc++.h>
using namespace std;
int t;
struct p{
	int a,b,c,d,e,f,g;
}s[100005];
bool cmp1(p x,p y){
	return x.e>y.e;
}
bool cmp2(p x,p y){
	return x.f>y.f;
}
bool cmp3(p x,p y){
	return x.g>y.g;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,cnta = 0,cntb = 0,cntc = 0,ans = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].d = max(max(s[i].a,s[i].b),s[i].c);
			if(s[i].d == s[i].a)cnta++;
			else if(s[i].d == s[i].b)cntb++;
			else if(s[i].d == s[i].c)cntc++;
			s[i].e = s[i].d-s[i].a,s[i].f = s[i].d-s[i].b,s[i].g = s[i].d-s[i].c;
		}
		for(int i = 1;i<=n;i++)ans+=s[i].d;
		if(cnta>n/2){
			sort(s+1,s+n+1,cmp1);
			for(int i = 1;i<=n;i++){
				if(s[i].d == s[i].a)continue;
				else  if(s[i].a == s[i].b||s[i].a == s[i].c)cnta--;
				else cnta--,ans-=(s[i].d-s[i].a);
			}
		}else if(cntb>n/2){
			sort(s+1,s+n+1,cmp2);
			for(int i = 1;i<=n;i++){
				if(s[i].d == s[i].b)continue;
				else  if(s[i].b == s[i].c)cntb--;
				else cntb--,ans-=(s[i].d-s[i].b);
			}
		}else if(cntc>n/2){
			sort(s+1,s+n+1,cmp3);
			for(int i = 1;i<=n;i++){
				if(s[i].d == s[i].c)continue;
				else cntc--,ans-=(s[i].d-s[i].c);
			}
		}
		cout <<ans<<"\n";
		memset(s,0,sizeof(s));
	}
	return 0;
}
