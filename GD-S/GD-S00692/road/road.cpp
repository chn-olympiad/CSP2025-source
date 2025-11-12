#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,cs[15],ans=1000000000000000,ans2,cnt;
long long rep[20000],tepv[20000],nn[1024];
struct ed{
	long long u,v,w;
};
bool cmp(ed x,ed y){
	return x.w<y.w;
}
int findf(int x){
	if(x!=rep[x]) rep[x]=findf(rep[x]);
	return rep[x];
}
void lianhe(int x,int y){
	rep[findf(x)]=findf(y);
}
vector<ed> basE,newE[15],E[1024],EE;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		basE.push_back({a,b,c});
	}
	sort(basE.begin(),basE.end(),cmp);
	for(int i=1;i<=k;i++){
		cin>>cs[i];
		for(int j=1;j<=n;j++){
			cin>>c;
			newE[i].push_back({n+i,j,c});
		}
		sort(newE[i].begin(),newE[i].end(),cmp);
	}
	int t=0;
	ans2=0;
	E[t]=basE;nn[t]=n;basE.clear();
	for(int i=1;i<=n;i++){
		tepv[i]=i;
	}
	//E:tn个点边xy在tepv x与tepv y之间，点为1~tn 
	for(int i=1;i<=nn[t];i++){
		rep[i]=i;
	}cnt=0;
	for(auto e:E[t]){
		a=tepv[e.u];b=tepv[e.v];c=e.w;//cout<<a<<' '<<b<<' '<<c<<endl;
		if(findf(a)!=findf(b)){
			lianhe(a,b);
			ans2+=c;cnt++;
			basE.push_back(e);
			if(ans2>=ans) break;
		}
		if(cnt==nn[t]-1) break;
	}
	ans=min(ans,ans2);
	E[0]=basE;
	for(t=1;t<=(1<<k)-1;t++){
		ans2=0;
		for(int i=1;i<=k;i++){
			if((t>>(i-1))%2==1){
				EE=E[t-(1<<(i-1))];nn[t]=nn[t-(1<<(i-1))]+1;tepv[i+n]=nn[t];
				int g=0,h=0;
				while(g+h<EE.size()+newE[i].size()){
					if(g==EE.size()) {
						E[t].push_back(newE[i][h]); h++;
					}
					else if(h==newE[i].size()){
						E[t].push_back(EE[g]);g++;
					}
					else {
						if(cmp(newE[i][h],EE[g])==1) {
							E[t].push_back(newE[i][h]);h++;
						}
						else{
							E[t].push_back(EE[g]);g++;
						}
					}
				}
				break;
			}
		}
		for(int i=1;i<=k;i++){
			if((t>>(i-1))%2==1){
				ans2+=cs[i];
			}	
		}
		//E:tn个点边xy在tepv x与tepv y之间，点为1~tn 
		for(int i=1;i<=nn[t];i++){
			rep[i]=i;
		}cnt=0;
		for(auto e:E[t]){
			a=tepv[e.u];b=tepv[e.v];c=e.w;//cout<<a<<' '<<b<<' '<<c<<endl;
			if(findf(a)!=findf(b)){
				lianhe(a,b);
				ans2+=c;cnt++;
				if(ans2>=ans) break;
			}
			if(cnt==nn[t]-1) break;
		}
		ans=min(ans,ans2);
	}
	cout<<ans;
	return 0;
} 
