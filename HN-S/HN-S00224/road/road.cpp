#include<bits/stdc++.h>
using namespace std;

struct node{
	vector<int>in_;
	vector<pair<int,int>>out_; 
}map_[100000];

int fa[1000005];

int father(int a){
	while(fa[a]!=a){
		father(fa[a]);
	}
	return fa[a];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		map_[u].out_.push_back(make_pair(v,w));
		map_[u].in_.push_back(v);
		map_[v].in_.push_back(u);
		map_[v].out_.push_back(make_pair(u,w));
	}
	for(int i=0;i<n+5;i++){
		fa[i]=i;
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			map_[i].out_.push_back(make_pair(j,a+c));
			map_[j].out_.push_back(make_pair(i,a+c));
			map_[i].in_.push_back(j);
			map_[j].in_.push_back(i);
		}
	}
	
	bool flag=1;
	bool flag1[1000]={1};
	int ans=0;
	memset(flag1,1,sizeof(flag1));
	while(flag){
		int mini=0;
		int minj=0;
		int mini_now=1;
		int minj_now=100000; 
		cout<<1<<endl;
//		cout<<"faj"<<" "<<father(minj)<<" "<<"fai"<<" "<<father(mini)<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<map_[i].out_.size();j++){
				if(map_[i].out_[j].second<minj_now){
					minj=j;
					minj_now=map_[i].out_[j].second;
					mini=i;
				}
			}
		}
//		cout<<"faj"<<" "<<father(minj)<<" "<<"fai"<<" "<<father(mini)<<endl;
//		cout<<minj_now<<" "<<mini<<endl;

		for(int i=0;i<10;i++){
			cout<<fa[i]<<" ";
		}
		cout<<endl;

		if(father(minj)!=father(mini)){
			flag1[fa[minj]]=0;
			cout<<1111111111;
//			flag1[fa[mini]]=0
			fa[minj]=fa[mini];
			ans+=map_[mini].out_[minj].second;
		}
		int tmpp=0;
		for(int i=0;i<n;i++){
			if(flag1[i]==1){
				tmpp++;
			}
	
		}
		if(tmpp<=1){
			flag=0;
		}
		
		
		
	}
	cout<<ans<<endl;
	
	
} 
