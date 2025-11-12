#include<bits/stdc++.h>
using namespace std;
int total=0;
struct pu{
	set<int> v;
	int sum;
	int z;
};
queue<pu> q;
void bfs(int y,vector<int> m){
	set<int> abc;
	abc.insert(m[0]);
	pu x={abc,m[0],0};
	q.push(x);
	while(!q.empty()){
		auto a=q.front();
		q.pop();
		set<int> now=a.v;
		int l=a.v.size();
		if(l==y){
		if(a.sum>now.front.end()*2){
			total++;
		}else{
			set new1=now;
			new1.insert(m[z+1]);
			q.push({new1,sum+m[z+1],z+1});
			q.push({now,sum,z+1});
			
		}
		
		
	}
	
}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> m(n);
	for(int i=0;i<n;i++){
			cin>>m[i];
	}
	sort(m.begin(),m.end());
	long long s=0;
	long long sum=0;
	for(int i=3;i<=n;i++){
		sum=0;
		for(int j=0;j<i;j++){
			sum+=m[j];
		}
		cout<<sum<<endl;
		for(int i=3;i<n;i++){
			bfs(i,m);
		}
	}
	cout<<s%998244353<<endl;
	return 0;
}
