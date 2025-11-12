#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5]; 
int cnt[5],b[5][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		int sum=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			int mx=max(max(a[i][1],a[i][2]),a[i][3]);
			if(mx==a[i][1]){
				++cnt[1];
				b[1][cnt[1]]=i;
			}else if(mx==a[i][2]){
				++cnt[2];
				b[2][cnt[2]]=i;
			}else{
				++cnt[3];
				b[3][cnt[3]]=i;
			}
			sum+=mx;
		}
		int id=0;
		for(int i=1;i<=3;++i){
			if(cnt[i]>n/2){
				id=i;
				break;
			}
		}
		if(id==0){
			cout<<sum<<'\n';
			continue;
		}
		priority_queue<int,vector<int>,greater<int> > q;
		if(id==1){
			for(int i=1;i<=cnt[id];++i){
				q.push(min(a[b[id][i]][1]-a[b[id][i]][2],a[b[id][i]][1]-a[b[id][i]][3]));
			}
		}else if(id==2){
			for(int i=1;i<=cnt[id];++i){
				q.push(min(a[b[id][i]][2]-a[b[id][i]][1],a[b[id][i]][2]-a[b[id][i]][3]));
			}
		}else{
			for(int i=1;i<=cnt[id];++i){
				q.push(min(a[b[id][i]][3]-a[b[id][i]][2],a[b[id][i]][3]-a[b[id][i]][1]));
			}	
		}
		int k=cnt[id]-n/2;
		while(k--){
			sum-=q.top();
			q.pop();
		}
		cout<<sum<<'\n';
	}	
	return 0;
} 
