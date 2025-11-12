#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+8;
#define ll long long
struct cl{
	int cnum,num;
};
struct stu{
	cl myi[6],m,cm;
	int h;
}s[mx];
bool cmp1(cl s1,cl s2){
	return s1.num>s2.num;
}
bool cmp2(stu s1,stu s2){
	if(s1.m.num!=s2.m.num){
		return s1.m.num>s2.m.num;
	}
	else return s1.cm.num>s2.cm.num;
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].myi[1].num,&s[i].myi[2].num,&s[i].myi[3].num);
		s[i].myi[1].cnum=1,s[i].myi[2].cnum=2,s[i].myi[3].cnum=3;
		s[i].h=i;
		sort(s[i].myi+1,s[i].myi+4,cmp1);
		s[i].m.cnum=s[i].myi[1].cnum,s[i].m.num=s[i].myi[1].num;
		s[i].cm.cnum=s[i].myi[2].cnum,s[i].cm.num=s[i].myi[2].num;
	}
	sort(s+1,s+n+1,cmp2);
	ll ans=0;
	int cnt[4]={};
	int club[4][mx/2]={};
	for(int i=1;i<=n;i++){
		int d1=s[i].m.num,d2=s[i].m.cnum;
		int cd1=s[i].cm.num,cd2=s[i].cm.cnum;
		if(cnt[d2]<n/2){
			club[d2][++cnt[d2]]=i;
			ans+=d1;
		}
		else{
			int old=club[d2][cnt[d2]];

			if(s[old].m.num+cd1>s[old].cm.num+d1){
				club[cd2][++cnt[cd2]]=i;
				ans+=cd1;
			}
			else{
				club[d2][cnt[d2]]=i;
				club[s[old].cm.cnum][++cnt[s[old].cm.cnum]]=old;
			}
			ans-=s[old].m.num;
			ans+=s[old].cm.num+d1;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
