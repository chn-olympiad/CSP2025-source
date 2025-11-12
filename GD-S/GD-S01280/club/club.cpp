#include <bits/stdc++.h>
using namespace std;
int T,n,maans;
struct stu{
	int a,b,c;
	bool f;
}st[114514];
stu ma;
int ta,tb,tc;
bool f1=1,f2=1;
bool cmpa(stu x,stu y){
	return x.a>y.a;
}
void dfs(int x,int ta,int tb,int tc,int ans){
	if(x==0){
		maans=max(ans,maans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i].f)continue;
		st[i].f=1;
		if(ta)dfs(x-1,ta-1,tb,tc,ans+st[i].a);
		if(tb)dfs(x-1,ta,tb-1,tc,ans+st[i].b);
		if(tc)dfs(x-1,ta,tb,tc-1,ans+st[i].c);
		st[i].f=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		maans=0;
		cin >> n;
		ta=n/2,tb=n/2,tc=n/2;
		for(int i=1;i<=n;i++)cin >> st[i].a >> st[i].b >> st[i].c;
		for(int i=1;i<=n;i++){
			if(st[i].c!=0){
				f1=0;
				f2=0;
				break;
			}else{
				if(st[i].b!=0)f1=0;
				break; 
			}
		}
		if(f1){
			int ans=0;
			sort(st+1,st+n+1,cmpa);
			for(int i=1;i<=n/2;i++)ans+=st[i].a;
			cout << ans << endl;
		}else if(f2){
			int i=n,ans=0;
			while(i>=0){
				if(st[i].a>st[i].b&&ta){
					ans+=st[i].a;
					ta--;
				}else if(st[i].a<st[i].b&&tb){
					ans+=st[i].b;
					tb--;
				}else{
					if(!ta){
						ans+=st[i].b;
						tb--;
					}else if(!tb){
						ans+=st[i].a;
						ta--;
					}else{
						if(ta>=tb){
							ta--;
							ans+=st[i].a;
						}else {
							tb--;
							ans+=st[i].b;
						}
					}
				}
				i--;
			}
			cout << ans;
		}else{
			dfs(n,ta,tb,tc,0);
			cout << maans << endl;
		}
		
	}
}

