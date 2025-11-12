#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
struct node{
	int a,b,c,k;
};
node q[N];
int t,n,m,aa,bb,cc;
long long ans;
void dfs(int wz,long long y,int aaa,int bbb,int ccc){
	if(aaa>m || bbb>m || ccc>m){
		return;
	}
	if(wz>n){
		ans=max(ans,y);
		return;
	}
	dfs(wz+1,y+q[wz].a,aaa+1,bbb,ccc);
	dfs(wz+1,y+q[wz].b,aaa,bbb+1,ccc);
	dfs(wz+1,y+q[wz].c,aaa,bbb,ccc+1);
}
bool cmp(node x,node y){
	return x.k>y.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			q[i].k=max(max(q[i].a,q[i].b),q[i].c);
		}
		m=n/2;
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}else{
			sort(q+1,q+n+1,cmp);
			aa=0,bb=0,cc=0;
			for(int i=1,l,o,oo;i<=n;i++){
				l=-1,o=0,oo=0;
				if(aa<m){
					l=q[i].a;
					o=1;
					oo=aa;
				}
				if(bb<m){
					if(l==q[i].b){
						o=((oo<bb) ? o : 2);
					}else if(l<q[i].b){
						l=q[i].b;
						o=2;
						oo=bb;
					}
				}
				if(cc<m){
					if(l==q[i].c){
						o=((oo<cc) ? o : 3);
					}else if(l<q[i].c){
						l=q[i].c;
						o=3;
						oo=cc;
					}
				}
				ans+=l;
				if(o==1){
					aa++;
				}else if(o==2){
					bb++;
				}else if(o==3){
					cc++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
