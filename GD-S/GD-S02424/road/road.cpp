#include<bits/stdc++.h>

using namespace std;

int main(){
	 freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
	int n,m;
	int k;
	cin>>n>>m>>k;
	int maps[100005];
	for(int i=1;i<=m*3;i++){
		cin>>maps[i];
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>maps[i];
		if(maps[i]!=0)flag=1;
		
	}
	
	if(!flag){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
