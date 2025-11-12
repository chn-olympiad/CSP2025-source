#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
struct node{
	int a1,a2,a3;
}s[100001];
struct node2{
	int id,val,maxn;
	bool operator<(const node2 &x)const{
	        return val-maxn>x.val-x.maxn;//小的在前面 
	}
};
priority_queue<node2>q1,q2,q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			if(max(max(s[i].a1,s[i].a2),s[i].a3)==s[i].a1){
				q1.push({i,s[i].a1,max(s[i].a2,s[i].a3)});
			}else if(max(max(s[i].a1,s[i].a2),s[i].a3)==s[i].a2){
				q2.push({i,s[i].a2,max(s[i].a1,s[i].a3)});
			}else{
				q3.push({i,s[i].a3,max(s[i].a2,s[i].a1)});
			}
		}
		while(q1.size()>n/2){
			int id=q1.top().id;
			if(s[id].a2>s[id].a3){
				q2.push({id,s[id].a2});
			}else{
				q3.push({id,s[id].a3});
			}
			q1.pop();
		}
		while(q2.size()>n/2){
			int id=q2.top().id;
			if(s[id].a1>s[id].a3){
				q1.push({id,s[id].a1});
			}else{
				q3.push({id,s[id].a3});
			}
			q2.pop();
		}
		while(q3.size()>n/2){
			int id=q3.top().id;
			if(s[id].a1>s[id].a2){
				q1.push({id,s[id].a1});
			}else{
				q2.push({id,s[id].a2});
			}
			q3.pop();
		}
		while(!q1.empty()){
			sum+=q1.top().val;
			q1.pop();
		}
		while(!q2.empty()){
			sum+=q2.top().val;
			q2.pop();
		}
		while(!q3.empty()){
			sum+=q3.top().val;
			q3.pop();
		}
		cout<<sum<<'\n';
		//我选择一个人到i那么中价值减去 
	}
	return 0;
}
