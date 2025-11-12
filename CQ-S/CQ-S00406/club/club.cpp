#include<bits/stdc++.h>
using namespace std;

namespace cl{
	int n;
	void solve(){
		priority_queue<int,vector<int>,greater<int>>pq1,pq2,pq3;
		cin>>n;
		int sum=0,k=n/2;
		for(int i=1;i<=n;i++){
			int v1,v2,v3;
			cin>>v1>>v2>>v3;
			int m=max({v1,v2,v3}),c=max({v1+v2,v2+v3,v3+v1})-m;
//			cout<<i<<' '<<v1<<' '<<v2<<' '<<v3<<'\n';
//			if(!pq1.empty())cout<<i<<' '<<'1'<<' '<<(pq1.top())<<'\n';
//			if(!pq2.empty())cout<<i<<' '<<'2'<<' '<<(pq2.top())<<'\n';
//			if(!pq3.empty())cout<<i<<' '<<'3'<<' '<<(pq3.top())<<'\n';
			if(v1==m){
				if(pq1.size()<k){
					pq1.push(v1-c);
					sum+=v1;
				}
				else{
					if(pq1.top()<v1-c){
						sum-=pq1.top();
						pq1.pop();
						pq1.push(v1-c);
						sum+=v1;
					}
					else{
						sum+=c;
					}
				}
			}
			else if(v2==m){
				if(pq2.size()<k){
					pq2.push(v2-c);
					sum+=v2;
				}
				else{
					if(pq2.top()<v2-c){
						sum-=pq2.top();
						pq2.pop();
						pq2.push(v2-c);
						sum+=v2;
					}
					else{
						sum+=c;
					}
				}
			}
			else if(v3==m){
				if(pq3.size()<k){
					pq3.push(v3-c);
					sum+=v3;
				}
				else{
					if(pq3.top()<v3-c){
						sum-=pq3.top();
						pq3.pop();
						pq3.push(v3-c);
						sum+=v3;
					}
					else{
						sum+=c;
					}
				}
			}
		}
		cout<<sum<<'\n';
	}
	int main(){
		int t=1;
		cin>>t;
		for(int i=1;i<=t;i++){
			solve();
		}
		return 0;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	return cl::main();
}
//15:19
