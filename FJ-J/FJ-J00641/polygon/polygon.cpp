#include<bits/stdc++.h>
using namespace std;

int bs,ab[5010],asb[5010];
long long zs;
bool sg[5010];

void dfs(int t,int z,int xb){
	if(t>z){
		int xbh=0;
		
		for(int i=1;i<t;i++){
			xbh+=asb[i];
		}
		
		if(xbh>(asb[t-1]*2)){
			zs++;
			zs%=998244353;
		}
		
		t--;
	}
	
	for(int i=xb+1;i<=bs;i++){
		if(!sg[i]){
			sg[i]=true;
			asb[t]=ab[i];
			
			dfs(t+1,z,i);
			
			sg[i]=false;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>bs;
	
	for(int i=1;i<=bs;i++){
		cin>>ab[i];
	}
	
	sort(ab+1,ab+1+bs);
	
	for(int i=3;i<=bs;i++){
		dfs(1,i,0);
	}
	
	cout<<zs%998244353;
	
	return 0;
}
