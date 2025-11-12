#include<bits/stdc++.h>
using namespace std; 
long long t,n,ans,sum;long long vt[300005];
struct que{
	long long p,v,g;
}a[300005];
long long b[300005][5];
bool operator<(que b,que c){
	return b.v>c.v;
}

long long cnt[5];
struct to{
	long long p,cost,ty;
};
bool operator<(to a,to b){
	return a.cost<b.cost;
}
priority_queue<to>q[15];
void in(int pos,int typ){
	for(int i=1;i<=3;i++){
		if(i==typ)continue;
		int t=(typ-1)*3+i;
		q[t].push({pos,b[pos][i]-b[pos][typ],typ});
	}
}
int gv1,gv2;
long long move(int st){
	long long res=-1e9,p=0,c=0;
	for(int i=1;i<=3;i++){
		if((cnt[i]==n/2 && i!=vt[st]))continue;
		int t=(st-1)*3+i;
		if(q[t].size()==0)continue;
		while(q[t].size()&&vt[q[t].top().p]!=q[t].top().ty)q[t].pop();
		if(q[t].size()&&(q[t].top().cost>res)){
			res=q[t].top().cost;
			c=q[t].top().p;p=i;
		}
	}gv1=p;gv2=c;
	return res;
}
void sol(){
	for(int i=1;i<=3*n;i++){
			int gs=a[i].g,ps=a[i].p;
			if(vt[ps]==0){
				if(cnt[gs]<n/2){
					cnt[gs]++;
					vt[ps]=gs;
					in(ps,gs);
				}else{
					int t=move(gs);
					if(t+b[ps][gs]>0){
						vt[ps]=gs;
						vt[gv2]=gv1;
						in(ps,gs);
						in(gv2,gv1);
						cnt[gv1]++;
					}
				}
			}else{
				if(cnt[gs]<n/2){
					if(b[ps][gs]>b[ps][vt[ps]]){
						cnt[gs]++;cnt[vt[ps]]--;
						vt[ps]=gs;
						in(ps,gs);
					}
					
				}else{
					int t=move(gs);
				//	cout<<gv2<<' '<<gv1<<'\n';
					if(t+b[ps][gs]-b[ps][vt[ps]]>0){
						cnt[gv1]++;
						cnt[vt[ps]]--;
						vt[ps]=gs;
						vt[gv2]=gv1;
						in(ps,gs);
						in(gv2,gv1);
					}
				}
			}
		//cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<' '<<sum<<'\n';
		}
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}for(int i=1;i<=9;i++)while(q[i].size())q[i].pop();
		for(int i=1;i<=n;i++){
			vt[i]=0;
			for(int j=1;j<=3;j++){
				cin>>b[i][j];
				a[(i-1)*3+j]={i,b[i][j],j};
			}
		}sort(a+1,a+3*n+1);
		sol();sol();
		ans=0;
		for(int i=1;i<=n;i++)ans+=b[i][vt[i]];
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/
