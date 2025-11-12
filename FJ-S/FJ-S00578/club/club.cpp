#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
struct node{
	int a,b,c;
}v[M];
int sum,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		priority_queue<int,vector<int>,greater<int> > qa,qb,qc;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			int maxx=max(v[i].a,max(v[i].b,v[i].c));
			if(v[i].a==maxx){
				sum+=v[i].a;
				int max2=max(v[i].b,v[i].c);
				qa.push(maxx-max2);
			}
			else if(v[i].b==maxx){
				sum+=v[i].b;
				int max2=max(v[i].a,v[i].c);
				qb.push(maxx-max2);
			}
			else if(v[i].c==maxx){
				sum+=v[i].c;
				int max2=max(v[i].b,v[i].a);
				qc.push(maxx-max2);
			}
		}
		while(qa.size()>n/2){
			int tot=qa.top();
			qa.pop();
			sum-=tot;
		}
		while(qb.size()>n/2){
			int tot=qb.top();
			qb.pop();
			sum-=tot;
		}
		while(qc.size()>n/2){
			int tot=qc.top();
			qc.pop();
			sum-=tot;
		}
		cout<<sum<<endl;
	}
	return 0;
}
