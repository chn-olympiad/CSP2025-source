#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct st{
	int m[4];
	int index;
}a[N+1];
int t,n;
long long sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		long long sum=0;
		vector<int>v[4];
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
		for(int i=1;i<=n;i++){		
			cin>>a[i].m[1]>>a[i].m[2]>>a[i].m[3];
			if(a[i].m[1]>=a[i].m[2]){
				if(a[i].m[3]>=a[i].m[1]){
					v[3].push_back(i);
					sum+=a[i].m[3];
				}
				else{
					v[1].push_back(i);
					sum+=a[i].m[1];
				}
			}
			else{
				if(a[i].m[3]>=a[i].m[2]){
					v[3].push_back(i);
					sum+=a[i].m[3];
				}
				else{
					v[2].push_back(i);
					sum+=a[i].m[2];
				}
			}
			a[i].index=i;
		}
		int idx=0,l;
		for(int i=1;i<=3;i++){
			if(v[i].size()>n/2){
				l=v[i].size();
				idx=i;
				break;
			}
		}
//		for(int i=1;i<=3;i++){
//			for(int j=0;j<v[i].size();j++){
//				cout<<v[i][j]<<' '<<i<<endl; 
//			}
//		}
//		cout<<v[1].size()<<' '<<v[2].size()<<' '<<v[3].size()<<endl;
//		cout<<sum<<endl;
		if(idx==0){
			cout<<sum<<endl;
			continue;
		}
		for(int i=0;i<l;i++){
			for(int j=1;j<=3;j++){
				if(j!=idx){
					int u=v[idx][i];
					int cj=a[u].m[j]-a[u].m[idx];
//					cout<<cj<<' '<<u<<' '<<j<<endl;
					q.push(make_pair(-cj,u));
				}
			}
		}
		bool f[N+1];
		memset(f,false,sizeof(f));
		while(l>n/2){
//			cout<<q.top().first<<' '<<q.top().second<<endl;
			if(!f[q.top().second]){
				sum-=q.top().first;
				f[q.top().second]=true;
				l--;
			}
			q.pop();
		}
		cout<<sum<<endl;
	}			
} 
