#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;

int n,ans;
struct node{
	int a,b,c;
};

vector<node>v;
priority_queue<int>qab,qac,qba,qbc,qca,qcb;

void solve(){
	v.clear();
	while(qab.size()) qab.pop();
	while(qac.size()) qac.pop();
	while(qba.size()) qba.pop();
	while(qbc.size()) qbc.pop();
	while(qca.size()) qca.pop();
	while(qcb.size()) qcb.pop();
	ans=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	
	for(int i=0;i<n;i++){
		if(v[i].a>v[i].b&&v[i].a>v[i].c){
			ans+=v[i].a;
			if(v[i].b>v[i].c)qab.push(v[i].b-v[i].a);
			else qac.push(v[i].c-v[i].a);
		} 
		else if(v[i].b>v[i].c&&v[i].b>v[i].a){
			ans+=v[i].b;
			if(v[i].a>v[i].c)qba.push(v[i].a-v[i].b);
			else qbc.push(v[i].c-v[i].b);
		} 
		else{
			ans+=v[i].c;
			if(v[i].a>v[i].b)qca.push(v[i].a-v[i].c);
			else qcb.push(v[i].b-v[i].c);
		}
	}
	
	while(qab.size()+qac.size()>n/2||qba.size()+qbc.size()>n/2||qca.size()+qcb.size()>n/2){
		if(qab.size()+qac.size()>n/2){
			if(qab.empty()){
				ans+=qac.top();
				qac.pop();				
			}else if(qac.empty()){
				ans+=qab.top();
				qab.pop();
			}else if(qab.top()>qac.top()){
				ans+=qab.top();
				qab.pop();
			}else{
				ans+=qac.top();
				qac.pop();
			}
		}else if(qba.size()+qbc.size()>n/2){
			if(qba.empty()){
				ans+=qbc.top();
				qbc.pop();				
			}else if(qbc.empty()){
				ans+=qba.top();
				qba.pop();				
			}else if(qba.top()>qbc.top()){
				ans+=qba.top();
				qba.pop();
			}else{
				ans+=qbc.top();
				qbc.pop();
			}
		}else{
			if(qca.empty()){
				ans+=qcb.top();
				qcb.pop();				
			}else if(qcb.empty()){
				ans+=qca.top();
				qca.pop();				
			}else if(qca.top()>qcb.top()){
				ans+=qca.top();
				qca.pop();
			}else{
				ans+=qcb.top();
				qcb.pop();
			}
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	ios::sync_with_stdio(0),std::cin.tie(0),cout.tie(0);
	int TTT=1;
	cin>>TTT;
	while(TTT--){
		solve();
	}
	return 0;
}
