#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,t1[200100],t2[200100],n,con1,con2,pda,pdb,ans=0,an,co[4];
struct clu{
	ll a,b,c,xh;
}stu[200100];
void dfs(ll wz,ll bm){
	if(wz==n+1){
		ans=max(ans,an);
		return;
	}
	if(co[bm]==n/2) return;
	co[bm]++;
	if(bm==1) an+=stu[wz].a;
	else if(bm==2) an+=stu[wz].b;
	else if(bm==3) an+=stu[wz].c;
	dfs(wz+1,1);
	dfs(wz+1,2);
	dfs(wz+1,3);
	co[bm]--;
	if(bm==1) an-=stu[wz].a;
	else if(bm==2) an-=stu[wz].b;
	else if(bm==3) an-=stu[wz].c;
	return;
}
bool cmpa(clu at,clu bt){
	if(at.a==bt.a) return at.xh<bt.xh;
	else return at.a>bt.a;
}
bool cmpb(clu at,clu bt){
	if(at.a-at.b==bt.a-bt.b) return at.xh<bt.xh;
	else return at.a-at.b<bt.a-bt.b;
}
/*
bool cmp1(clu at,clu bt){
	if(at.a-at.b<bt.a-bt.b) return true;
	else if(at.a-at.b>bt.a-bt.b) return false;
	else return at.xh<bt.xh;
}
bool cmp2(clu at,clu bt){
	if(at.a-at.c<bt.a-bt.c) return true;
	else if(at.a-at.c>bt.a-bt.c) return false;
	else return at.xh<bt.xh;
}
*/
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;
		pda=1;
		pdb=1;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			if(stu[i].c!=0){
				pda=0;
				pdb=0;
			}
			else if(stu[i].b!=0){
				pdb=0;
			}
			stu[i].xh=i;
		}
		if(n<=30){
			an=0;
			ans=0;
			co[1]=0;
			co[2]=0;
			co[3]=0;
			dfs(1,1);
			dfs(1,2);
			dfs(1,3);
			cout<<ans<<endl;
		}
		else if(pdb==1){
			sort(stu+1,stu+n+1,cmpa);
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=stu[i].a;
			}
			cout<<ans<<endl;
		}
		else if(pda==1){
			for(int i=1;i<=n;i++){
				ans+=stu[i].a; 
			} 
			sort(stu+1,stu+n+1,cmpb);
			for(int i=1;i<=n/2;i++){
				ans=ans+stu[i].b-stu[i].a;
			}
			cout<<ans<<endl;
		}
		else{
			an=0;
			ans=0;
			co[1]=0;
			co[2]=0;
			co[3]=0;
			dfs(1,1);
			dfs(1,2);
			dfs(1,3);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
