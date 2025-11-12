#include<bits/stdc++.h>
#define int long long
using namespace std;
int tt;
struct stu{
	int a,b,c,fsx;
	char f,s,t;
}st[100007];
bool cmp(stu p,stu q){
	return p.fsx>q.fsx;
}
void pd(){
	int n,aa=0,bb=0,cc=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].b>>st[i].c;
		if(st[i].a>=st[i].b&&st[i].a>=st[i].c&&st[i].b>=st[i].c) st[i].f='a',st[i].s='b',st[i].t='c',st[i].fsx=st[i].a-st[i].b;
		else if(st[i].a>=st[i].c&&st[i].a>=st[i].b&&st[i].c>=st[i].b) st[i].f='a',st[i].s='c',st[i].t='b',st[i].fsx=st[i].a-st[i].c;
		else if(st[i].b>=st[i].a&&st[i].b>=st[i].c&&st[i].a>=st[i].c) st[i].f='b',st[i].s='a',st[i].t='c',st[i].fsx=st[i].b-st[i].a;
		else if(st[i].b>=st[i].c&&st[i].b>=st[i].a&&st[i].c>=st[i].a) st[i].f='b',st[i].s='c',st[i].t='a',st[i].fsx=st[i].b-st[i].c;
		else if(st[i].c>=st[i].a&&st[i].c>=st[i].b&&st[i].a>=st[i].b) st[i].f='c',st[i].s='a',st[i].t='b',st[i].fsx=st[i].c-st[i].a;
		else if(st[i].c>=st[i].b&&st[i].c>=st[i].a&&st[i].b>=st[i].a) st[i].f='c',st[i].s='b',st[i].t='a',st[i].fsx=st[i].c-st[i].b;
	}
	sort(st+1,st+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(st[i].f=='a'&&aa+1<=n/2) ans+=st[i].a,aa++;
		else if(st[i].f=='b'&&bb+1<=n/2) ans+=st[i].b,bb++;
		else if(st[i].f=='c'&&cc+1<=n/2) ans+=st[i].c,cc++;
		else if(st[i].f=='a'&&aa+1>n/2){
			if(st[i].s=='b') ans+=st[i].b,bb++;
			else if(st[i].s=='c') ans+=st[i].c,cc++;
		}
		else if(st[i].f=='b'&&bb+1>n/2){
			if(st[i].s=='a') ans+=st[i].a,aa++;
			else if(st[i].s=='c') ans+=st[i].c,cc++;
		}
		else if(st[i].f=='c'&&cc+1>n/2){
			if(st[i].s=='a') ans+=st[i].a,aa++;
			else if(st[i].s=='b') ans+=st[i].b,bb++;
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tt;
	while(tt--) pd();
	return 0;
}
