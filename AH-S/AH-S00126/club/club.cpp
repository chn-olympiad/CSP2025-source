#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct data{int a,b,c,d,m;}s[N];
struct node{int aa,tp;};
int T,n;
bool cmp(node x,node y){
	return x.tp>y.tp;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
		cin>>n;
		int s1=0,s2=0,s3=0;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int sf[4];
			sf[1]=s[i].a,sf[2]=s[i].b,sf[3]=s[i].c;
			sort(sf+1,sf+4);
			s[i].d=sf[3]-sf[2],s[i].m=sf[3];
			if(s[i].a==sf[3]) s1++,cnt+=sf[3];
			else if(s[i].b==sf[3]) s2++,cnt+=sf[3];
			else s3++,cnt+=sf[3];
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			cout<<cnt<<'\n';
			continue;
		}
		else if(s1>n/2){
			node ans[N];
			bool f[N];int t=0;
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			    if(s[i].a==s[i].m)
			        ans[++t].aa=s[i].a,ans[t].tp=s[i].d,f[i]=1;
			sort(ans+1,ans+1+t,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2&&i<=t;i++)
			    cnt+=ans[i].aa;
			for(int i=n/2+1;i<=t;i++)
			    cnt+=(ans[i].aa-ans[i].tp);
			for(int i=1;i<=n;i++)
			    if(f[i]==0) cnt+=s[i].m;
			cout<<cnt<<'\n';
		}
		else if(s2>n/2){
			node ans[N];
			bool f[N];int t=0;
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			    if(s[i].b==s[i].m)
			        ans[++t].aa=s[i].b,ans[t].tp=s[i].d,f[i]=1;
			sort(ans+1,ans+1+t,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2&&i<=t;i++)
			    cnt+=ans[i].aa;
			for(int i=n/2+1;i<=t;i++)
			    cnt+=(ans[i].aa-ans[i].tp);
			for(int i=1;i<=n;i++)
			    if(f[i]==0) cnt+=s[i].m;
			cout<<cnt<<'\n';
		}
		else if(s3>n/2){
			node ans[N];
			bool f[N];int t=0;
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			    if(s[i].c==s[i].m)
			        ans[++t].aa=s[i].c,ans[t].tp=s[i].d,f[i]=1;
			sort(ans+1,ans+1+t,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2&&i<=t;i++)
			    cnt+=ans[i].aa;
			for(int i=n/2+1;i<=t;i++)
			    cnt+=(ans[i].aa-ans[i].tp);
			for(int i=1;i<=n;i++)
			    if(f[i]==0) cnt+=s[i].m;
			cout<<cnt<<'\n';
		}
	}
    return 0;
}
