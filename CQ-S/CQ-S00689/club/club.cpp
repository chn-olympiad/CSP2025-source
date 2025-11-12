#include<bits/stdc++.h>           
using namespace std;
long long n,m,re[4];
struct node{
	long long x,y,z,sx,sy,sz;
}t[100010];
struct paixu{
	long long num,man;
};
bool cmp(paixu a,paixu b){
	return a.man>b.man;
}
bool cmq(node g,node h){
	if(g.x==h.x){
		if(g.y==h.y) return g.z>h.z;
		else return g.y>h.y;
	}
	else return g.x>h.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m--){
		long long ans=0;
		cin>>n;
		re[1]=n/2,re[2]=n/2,re[3]=n/2;
		for(int i=1;i<=n;i++){
			paixu s[5];
		    for(int j=1;j<=3;j++){
		    	cin>>s[j].man;
		    	s[j].num=j;
			}
			sort(s+1,s+4,cmp);
		    t[i].x=s[1].man,t[i].sx=s[1].num;
		    t[i].y=s[2].man,t[i].sy=s[2].num;
		    t[i].z=s[3].man,t[i].sz=s[3].num;
		}
		sort(t+1,t+n+1,cmq);
		for(int i=1;i<=n;i++){
			
			if(re[t[i].sx]>0){
				ans+=t[i].x;
				re[t[i].sx]--;
				continue;
			}
			if(re[t[i].sy]>0){
				ans+=t[i].y;
				re[t[i].sy]--;
				continue;
			}
			if(re[t[i].sz]>0){
				ans+=t[i].z;
				re[t[i].sz]--;
				continue;
			}
		}
		cout<<ans<<'\n';
		memset(t,0,sizeof(t));
	}
	return 0;
}
