#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int const D=1e5+50;
struct Node{
	int x,y,z;
};
Node a[D];
struct node{
	int ip;
	int kl;
	Node num;
};
vector<node>s[3];
vector<int>l;
int fun(Node p){
	l.clear();
	l.push_back(p.x);l.push_back(p.y);l.push_back(p.z);
	sort(l.begin(),l.end());
	return l[2]-l[1];
} 
bool cmp(node p,node q){
	return fun(p.num)<fun(q.num);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<3;i++){
			s[i].clear();
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)s[0].push_back(node{i,a[i].x,a[i]});
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)s[1].push_back(node{i,a[i].y,a[i]});
			else s[2].push_back(node{i,a[i].z,a[i]});
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<s[i].size();j++){
				ans+=s[i][j].kl;
			}
		}
		for(int i=0;i<3;i++){
			if(s[i].size()>n/2){
				sort(s[i].begin(),s[i].end(),cmp);
				for(int j=0;j<s[i].size()-n/2;j++){
					ans=ans-fun(s[i][j].num);
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
