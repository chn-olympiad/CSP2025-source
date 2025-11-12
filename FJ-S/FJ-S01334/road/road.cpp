#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=4;
int city[1005][1005]={0};
vector<vector<int> > town;
bool acc[1005]={false};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		city[a][b]=c;
		city[b][a]=c;
	}
	town.reserve(k);
	for(int i=0;i<k;i++){
		vector<int> tmp;
		int fee;
		cin>>fee;
		tmp.push_back(fee);
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			tmp.push_back(t);
		}
		town.push_back(tmp);
	}
	int now=1,way=1;
	int line=0;
	int minfee=99999;
	while(!canout){
		canout=true;
		for(int i=1;i<=n;i++){
			if(acc[i]=false){
				canout=false;
			}
		}
	}
	cout<<ans;
} 
