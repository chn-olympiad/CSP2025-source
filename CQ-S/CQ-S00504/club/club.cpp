#include<bits/stdc++.h>
using namespace std;
struct nooo{
	int id;
	int z;
};
nooo cnt2[100100][5];
struct noo{
	int id;
	int hh;
	int zhi;
	bool operator <(const noo &ot)const{
		if(zhi==ot.zhi){
			if(hh==3){
				return zhi<ot.zhi;
			}
			if(ot.hh==3){
				return zhi>ot.zhi;
			}
			return cnt2[id][hh+1].z>cnt2[ot.id][ot.hh+1].z;
		}
		return zhi>ot.zhi; 
	}
};
priority_queue<noo> a[4];
int cmp(nooo a,nooo b){
	if(a.z==b.z){
		return a.id<b.id;
	}
	return a.z>b.z;
}
void solve(){
	int n;
	cin>>n;
	while(!a[0].empty()){
		a[0].pop();
	}
	while(!a[1].empty()){
		a[1].pop();
	}
	while(!a[2].empty()){
		a[2].pop();
	}
	while(!a[3].empty()){
		a[3].pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
            int aa;
			cin>>aa;
			cnt2[i][j]={j,aa};
		}
		sort(cnt2[i]+1,cnt2[i]+1+3,cmp);
	}
	int sum[10];
	sum[1]=0;
	sum[2]=0;
	sum[3]=0;
	int ans=0; 
	for(int i=1;i<=n;i++){
		if(sum[cnt2[i][1].id]<n/2){
			sum[cnt2[i][1].id]++;
			ans+=cnt2[i][1].z;
			a[cnt2[i][1].id].push({i,1,cnt2[i][1].z});
//			cout<<"!"<<ans<<"\n";
		}else{
			int oold=cnt2[i][2].z;//+a[cnt2[i][1].id].top().zhi;
			//cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh+1].z
			int nnew=cnt2[i][1].z+cnt2[ a[cnt2[i][1].id].top().id ][ cnt2[ a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh+1 ].z ].z-cnt2[a[cnt2[i][1].id].top().id][cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh].z].z; 
//			int nnew=cnt2[i][1].z+cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh+1].z-cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh].z;//a[cnt2[i][1].id].top().zhi;
//			cout<<"@"<<ans;
//			cout<<cnt2[i][1].z<<" "<<cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh+1].z<<" "<<a[cnt2[i][1].id].top().hh<<"\n";
//			cout<<oold<<" "<<nnew<<" "<<a[cnt2[i][1].id].top().id<<" "<<a[cnt2[i][1].id].top().hh<<" "<<cnt2[i][1].id<<" "<<cnt2[i][1].z<<" "<<cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh+1].z<<" "<<cnt2[a[cnt2[i][1].id].top().id][a[cnt2[i][1].id].top().hh].z<<"\n"; 
			if(a[cnt2[i][1].id].top().hh==3||oold>nnew){
				sum[cnt2[i][2].id]++;
				ans+=oold;
				a[cnt2[i][2].id].push({i,2,cnt2[i][2].z});
			}else{
//				cout<<"########";
				ans+=nnew;
				noo now=a[cnt2[i][1].id].top();
//				cout<<"\n"<<now.id<<" "<<cnt2[now.id][now.hh].id<<" "<<now.zhi<<"\n";
				a[cnt2[i][1].id].pop();
				a[cnt2[i][1].id].push({i,1,cnt2[i][1].z});
				now.hh++;
				sum[cnt2[now.id][now.hh].id]++;
//				cout<<now.hh<<"******"<<"\n";
				now.zhi=cnt2[now.id][now.hh].z;
				a[cnt2[now.id][now.hh].id].push(now);
			}
//			cout<<" "<<ans<<"\n"; 
		}
//		cout<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<"\n"; 
		
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cout<<cnt2[i][j].id<<":"<<cnt2[i][j].z<<" ";
//		}
//		cout<<"\n";
//	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}

