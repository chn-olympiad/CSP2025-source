#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100005
#define ll long long
ll n,m,a[N][4],id1,id2,id3,ans,mid2,mid3,ans1,ans2,cntb;
struct node{
	ll v,id;
}mapr[N];
node b[N];
vector<node> vt[4];
bool cmp(node a,node b){
	return a.v<b.v;
}
bool cmpb1(node x,node y){
	return min(a[x.id][1]-a[x.id][2],a[x.id][1]-a[x.id][3])<min(a[y.id][1]-a[y.id][2],a[y.id][1]-a[y.id][3]);
}
bool cmpb2(node x,node y){
	return min(a[x.id][2]-a[x.id][1],a[x.id][2]-a[x.id][3])<min(a[y.id][2]-a[y.id][1],a[y.id][2]-a[y.id][3]);
}
bool cmpb3(node x,node y){
	return min(a[x.id][3]-a[x.id][2],a[x.id][3]-a[x.id][1])<min(a[y.id][3]-a[y.id][2],a[y.id][3]-a[y.id][1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		vt[1].clear();
		vt[2].clear();
		vt[3].clear();
		ans=0;
		cntb=0;
		ans1=ans2=0;
		int ans3=0;
		id1=id2=id3=0;
		mid3=mid2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mid2=max(mid2,a[i][2]);mid3=max(mid3,a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				mapr[i].v=a[i][1];
				mapr[i].id=1;
				vt[1].push_back({a[i][1],i});
				id1++;
				ans1+=a[i][1];
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				mapr[i].v=a[i][2];
				mapr[i].id=2;
				id2++;
				vt[2].push_back({a[i][2],i});
				ans2+=a[i][2];
			}
			else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]){
				mapr[i].v=a[i][3];
				mapr[i].id=3;
				id3++;
				vt[3].push_back({a[i][3],i});
				ans3+=a[i][3];
			}
		}
		if(mid2==0 && mid3==0){
			sort(vt[1].begin(),vt[1].end(),cmp);
			for(int i=0;i<n/2;i++){
				ans1-=vt[1][i].v;
			}
			cout<<ans1<<endl;
			continue;
		}
		else if(mid3==0){
			if(id1>n/2){
				sort(vt[1].begin(),vt[1].end(),cmp1);
				for(int i=0;i<id1-n/2;i++){
					ans1-=vt[1][i].v;
					ans2+=a[vt[1][i].id][2];
				}
				cout<<ans1+ans2<<endl;
				continue;
			}
			else if(id2>n/2){
				sort(vt[2].begin(),vt[2].end(),cmp2);
				for(int i=0;i<id2-n/2;i++){
					ans1+=a[vt[2][i].id][1];
					ans2-=vt[2][i].v;
				}
				cout<<ans1+ans2<<endl;
				continue;
			}
			
		}
		if(id1>n/2){
			sort(vt[1].begin(),vt[1].end(),cmp);
			for(int i=0;i<id1-n/2;i++){
				b[++cntb].v=vt[1][i].v;
				b[++cntb].id=vt[1][i].id;
			}
			sort(b+1,b+1+cntb,cmpb1);
			for(int i=1;i<=cntb;i++){
				ans1-=min(a[b[i].id][1]-a[b[i].id][2],a[b[i].id][1]-a[b[i].id][3]);
			}
			cout<<ans1<<endl;
			continue;
		}
		if(id2>n/2){
			sort(vt[2].begin(),vt[2].end(),cmp);
			for(int i=0;i<id2-n/2;i++){
				b[++cntb].v=vt[2][i].v;
				b[++cntb].id=vt[2][i].id;
			}
			sort(b+1,b+1+cntb,cmpb2);
			for(int i=1;i<=cntb;i++){
				ans2-=min(a[b[i].id][2]-a[b[i].id][1],a[b[i].id][2]-a[b[i].id][3]);
			}
			cout<<ans2<<endl;
			continue;
		}
		if(id3>n/2){
			sort(vt[3].begin(),vt[3].end(),cmp);
			for(int i=0;i<id3-n/2;i++){
				b[++cntb].v=vt[3][i].v;
				b[++cntb].id=vt[3][i].id;
			}
			sort(b+1,b+1+cntb,cmpb3);
			for(int i=1;i<=cntb;i++){
				ans3-=min(a[b[i].id][3]-a[b[i].id][1],a[b[i].id][3]-a[b[i].id][2]);
			}
			cout<<ans3<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][mapr[i].id];
		}
		cout<<ans<<endl;
	}
	return 0;
}