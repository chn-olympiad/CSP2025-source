#include<bits/stdc++.h>

using namespace std;

struct node{
	int d,vl,ip;
	
	bool operator <(const node &ano)const {
		return ano.vl>vl;
	}
};

const int N=1e5+5;

int T;






int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	
	while(T--){
		priority_queue<node>q;
		map<int,int>mp;
		map<int,int>pe;
		int n;
		int cnt[5];
		for(int i=1;i<=5;i++) cnt[i]=0;
		int a[N][5];
		vector<int>di[5];
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans+=a[i][1];
			q.push({2,a[i][2]-a[i][1],i});
			q.push({3,a[i][3]-a[i][1],i});
			pe[i]=1;
		}
		while(q.size()){
			int d=q.top().d;
			int vl=q.top().vl;
			int ip=q.top().ip;
			
			q.pop();
			
			if(cnt[d]>=n/2 || mp[ip]==1){
				continue;
			}
			if(vl>0){
				ans+=vl;
				pe[ip]=d;
				mp[ip]=1;
				cnt[d]++;
			}
		}
		for(int i=1;i<=n;i++){
			di[pe[i]].push_back(i);
		}
		int f=0;
		for(int i=1;i<=3;i++){
			if(di[i].size()>n/2){
				f=i;
			}
			cnt[i]=di[i].size();
		}
		if(f==0){
			cout<<ans<<endl;
			continue;
		}
		//»»f
		while(q.size()){
			q.pop();
		}
		for(int i=1;i<=n;i++) mp[i]=0;
		for(auto t:di[f]){
//			cout<<t<<endl;
			for(int i=1;i<=3;i++){
				if(f==i) continue;
//				cout<<i<<endl;
				q.push({i,a[t][i]-a[t][f],t});
//				cout<<endl<<i<<' '<<a[t][i]-a[t][f]<<' '<<t<<endl;
			}
		}
//		int h=0;
//		while(q.size()){
//			q.pop();
//			h++;
//		}
//		cout<<h<<endl;
		for(int i=1;i<=di[f].size()-(n/2);i++){
			while(q.size()){
				int d=q.top().d;
				int vl=q.top().vl;
				int ip=q.top().ip;
				
//				cout<<endl<<d<<' '<<vl<<' '<<ip<<endl;
			
				
			
				if(di[d].size()>=n/2 || mp[ip]==1){
//					cout<<"pass\n";
					q.pop();
					continue;
				}else{
					break;
				}
			}
			int d=q.top().d;
			int vl=q.top().vl;
			int ip=q.top().ip;
			
			ans+=vl;
			mp[ip]=1;
			di[d].push_back(f);
		}
		cout<<ans<<endl;
	}
	return 0;
}
