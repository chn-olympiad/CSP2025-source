#include<bits/stdc++.h>
using namespace std;
#define int long long
int rs[10];
struct S{
	int a,b,c,ma,fs,mi,fs1;
}s[100001];
bool cmp(S x,S y){
	if(x.ma!=y.ma) return x.ma>y.ma;
	if(x.mi!=y.mi) return x.mi>y.mi;
	return min(x.a,min(x.b,x.c))>min(y.a,min(y.b,y.c));
}
tuple<int,int,int,int> f[100001][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T; 
	while(T--){
		memset(rs,0,sizeof rs);
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].ma = max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].ma==s[i].a) s[i].fs = 1;
			else if(s[i].ma==s[i].b) s[i].fs = 2;
			else if(s[i].ma==s[i].c) s[i].fs = 3;
			if(s[i].fs==1){
				s[i].mi = max(s[i].b,s[i].c);
				if(s[i].mi==s[i].b) s[i].fs1= 2;
				else s[i].fs1 = 3;
			}
			else if(s[i].fs==2){
				s[i].mi = max(s[i].a,s[i].c);
				if(s[i].mi==s[i].a) s[i].fs1= 1;
				else s[i].fs1 = 3;
			}
			else if(s[i].fs==3){
				s[i].mi = max(s[i].b,s[i].a);
				if(s[i].mi==s[i].b) s[i].fs1= 2;
				else s[i].fs1 = 1;
			}
		}
		int ans = 0;
		sort(s+1,s+n+1,cmp);
		//printf("xxxxxxxxx\n");
		//for(int i = 1;i<=n;i++)
		//	printf("%d %d %d\n",s[i].a,s[i].b,s[i].c);
		for(int i = 1;i<=n;i++){
			if(rs[s[i].fs]<=n/2-1){
				rs[s[i].fs]++;
				ans+=s[i].ma;
				//printf("x %d ",s[i].fs);
			}
			else{
				rs[s[i].fs1]++;
				ans+=s[i].mi;
				//printf("xx %d %d ",rs[s[i].fs],s[i].fs1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
