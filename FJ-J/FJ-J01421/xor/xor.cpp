#include<bits/stdc++.h>
#define int long long

using namespace std;


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,xormask;
	cin>>n>>xormask;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
		nums[i] ^= xormask;
	}
	
	map<int,int> appear;
	appear[0]=1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pairs;
	int ttxor = 0;
	for(int i=0;i<n;i++){
		ttxor ^= nums[i];
		if(appear[ttxor]){
			if((pairs.empty() || pairs.top().first < appear[ttxor]) && ((appear[ttxor]+i) %2 ==0) ){
				pairs.push({appear[ttxor],i+1});
			}
		}
		if(appear[ttxor^xormask]){
			if((pairs.empty() || pairs.top().first < appear[ttxor]) && ((appear[ttxor]+i) %2 ==1) ){
				pairs.push({appear[ttxor],i+1});
			}
		}
		
		appear[ttxor]=i+2;
	}
	
	int ans=0,DISRAPUTION=2147483647;
	while(!pairs.empty()){
		if(pairs.top().second<DISRAPUTION){
			//cout<<pairs.top().first<<' '<<pairs.top().second<<endl;
			ans++;
			DISRAPUTION=min(pairs.top().first,DISRAPUTION);
		}
		pairs.pop();
	}
	cout<<ans;
	return 0;
}
