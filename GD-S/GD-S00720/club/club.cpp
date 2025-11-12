#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
using LL = long long;
LL t,n,cnt_b,cnt_c,sum=0;
struct student{
	LL a,b,c;
}s[N];
bool cmp(student &x,student &y){
	return x.a>y.a;
}
void dfs(LL now,LL cnta,LL cntb,LL cntc,LL cnt){
	if(cnta>n/2||cntb>n/2||cntc>n/2) return ;
	if(now==n+1){
		sum=max(sum,cnt);
		return ;
	}
	dfs(now+1,cnta+1,cntb,cntc,cnt+s[now].a);
	dfs(now+1,cnta,cntb+1,cntc,cnt+s[now].b);
	dfs(now+1,cnta,cntb,cntc+1,cnt+s[now].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt_b=0,cnt_c=0;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b) cnt_b++;
			if(s[i].c) cnt_c++;
		}
		if(cnt_b==0&&cnt_c==0){
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=s[i].a;
			}
			cout<<sum<<'\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
