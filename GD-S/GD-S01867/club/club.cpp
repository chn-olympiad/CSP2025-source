#include<bits/stdc++.h>
using namespace std;
int t,n,pos,sum[101],ans;
struct node{int v,x;}a[100010][5];
vector<int> v;
bool cmp(node l,node r){return l.v>r.v;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n,v.clear(),sum[1]=sum[2]=sum[3]=ans=pos=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v,a[i][1].x=1,a[i][2].x=2,a[i][3].x=3;
			sort(a[i]+1,a[i]+3+1,cmp);
			ans+=a[i][1].v,sum[a[i][1].x]++;
		for(int i=1;i<=3;i++){
			if(sum[i]>n/2)pos=i;
		}
		if(!pos){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1].x==pos)v.push_back(a[i][1].v-a[i][2].v);
		}
		sort(v.begin(),v.end());
		for(int i=n/2+1;i<=sum[pos];i++)ans-=v[i-(n/2+1)];
		cout<<ans<<'\n';
	}
}
