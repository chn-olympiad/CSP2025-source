#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int T,n;
struct Stu {
	pair<int,int> p[3];
	friend bool operator <(Stu a,Stu b) {
		return(a.p[0].F>b.p[0].F);
	}
} s[100010];
bool cmp(Stu a,Stu b) {
	return (a.p[1].F!=b.p[1].F?a.p[1].F>b.p[1].F:a.p[0].F>b.p[0].F);
}
int cnt[3];
long long ans;
int f[100010];
void dfs(int id) {
	if(id==n+1) {
		long long k=0;
		for(int i = 1; i<=n; i++) k+=s[i].p[f[i]].F;
		ans=max(ans,k);
	}
	for(int i = 0; i<3; i++) {
		f[id]=i;
		cnt[i]++;
		if(*max_element(cnt,cnt+3)<=n/2)
			dfs(id+1);
		cnt[i]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		bool f1=1,f2=1;
		for(int i = 1; i<=n; i++) {
			for(int j = 0; j<3; j++) {
				cin>>s[i].p[j].F;
				if(j!=1&&s[i].p[j].F!=0) f1=0;
				if(j==3&&s[i].p[j].F!=0) f2=0;
				s[i].p[j].S=j;
			}
		}
		if(f1||f2) {
			long long a1=0,a2=0;
			sort(s+1,s+n+1);
			for(int i = 1; i<=(n>>1); i++) a1+=s[i].p[0].F;
			if(f2) {
				sort(s+1,s+n+1,cmp);
				for(int i = 1; i<=n; i++) if(i<=(n>>1)) a2+=s[i].p[1].F;
					else a2+=s[i].p[0].F;
			}
			cout<<max(a1,a2)<<"\n";
		} else {
			if(n<=12) {
				dfs(1);
				continue;
			}
			for(int i = 1; i<=n; i++)
				sort(s[i].p,s[i].p+3);
			sort(s+1,s+n+1);
			for(int i = 1; i<=n; i++) {
				if(cnt[s[i].p[2].S]+1<=n/2) {
					cnt[s[i].p[2].S]++;
					ans+=s[i].p[2].F;
				} else {
					cnt[s[i].p[1].S]++;
					ans+=s[i].p[1].F;
				}
			}

			cout<<ans<<"\n";
		}
	}
	return 0;
}

