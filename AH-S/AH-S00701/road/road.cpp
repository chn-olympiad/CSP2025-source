#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,h[20],vis[10020],ans;
//int v[10020][10020];
struct node{
	int p,q,w;
}t;
vector <node> l,ad;
int cmp(node a,node b){
	if(a.q>n) return a.w+h[a.q-n]<b.w+h[b.q-n];
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//memset(v,127,sizeof(v));
	for(int i=1;i<=m;i++){
		cin>>t.p>>t.q>>t.w;
		l.push_back(t);
		//v[t.p][t.q]=v[t.p][t.q]=t.w;
	}
	for(int i=1;i<=k;i++){
		cin>>h[i];
		for(int j=1;j<=n;j++){
			cin>>t.w;
			//v[j][n+i]=v[n+i][j];
			t.p=j;t.q=n+i;
			ad.push_back(t);
		}
	}
	sort(l.begin(),l.end(),cmp);
	sort(ad.begin(),ad.end(),cmp);
	int cur1=0,cur2=0;
	for(int i=1,j=0;j<n;i++){
		//cout<<i<<" "<<j<<"\n";
		//cout<<l[cur1].p<<" "<<l[cur1].q<<" "<<l[cur1].w<<"\n";
		//cout<<ad[cur2].p<<" "<<ad[cur2].q<<" "<<ad[cur2].w<<"\n";
		if(k==0){
			t=l[cur1];
			//cout<<t.p<<" "<<t.q<<" "<<t.w<<" ";
			cur1++;
			if(vis[t.p]==1&&vis[t.q]==1) continue;
			ans+=t.w;
			//cout<<ans;
			j+=2-vis[t.p]-vis[t.q];
			vis[t.p]=1;vis[t.q]=1;
		}
		else if(ad[cur2].w+h[ad[cur2].q-n]*(1-vis[ad[cur2].q])>l[cur1].w){
			t=l[cur1];
			//cout<<t.p<<" "<<t.q<<" "<<t.w<<" ";
			cur1++;
			if(vis[t.p]==1&&vis[t.q]==1) continue;
			ans+=t.w;
			//cout<<ans;
			j+=2-vis[t.p]-vis[t.q];
			vis[t.p]=1;vis[t.q]=1;
		}
		else{
			t=ad[cur2];
			//cout<<t.p<<" "<<t.q<<" "<<t.w<<" ";
			cur2++;
			if(vis[t.p]==1) continue;
			ans+=t.w;
			if(vis[t.q]==0){
				ans+=h[t.q-n];
			}
			//cout<<ans;
			j+=1;
			vis[t.p]=1;vis[t.q]=1;
		}
		//cout<<ans<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
