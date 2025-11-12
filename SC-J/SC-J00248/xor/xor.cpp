#include<bits/stdc++.h>
using namespace std;
queue<int>q;
long long n,m,a[500005],qzh[500005],sum,vis[500005];
bool pd(long long x,long long y){
	for(int i=x+1;i<=y;i++){
		if(vis[i]==1) return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m) sum++,vis[i]=1,q.push(i);
	} 
	for(int i=1;i<=n;i++){
		qzh[i]=(qzh[i-1]^a[i]);
	}
	if(!q.empty()){
		for(int i=1,j=1;i<q.back();i=j){
			while((qzh[j]^qzh[i-1])!=m && j<q.back()){
				j++;
				//cout<<i<<" "<<j<<" "<<(qzh[j]^qzh[i-1])<<" "<<sum<<"\n";
			}
			if((qzh[j]^qzh[i-1])==m) sum++;
		//	cout<<i<<" "<<j<<" "<<(qzh[j]^qzh[i-1])<<" "<<sum<<"\n";
		}
	}
	while(!q.empty()){
		int x=q.back();
		q.pop();
		if(q.size()>0){
			for(int i=x+1,j=x+1;i<q.back();i=j){
				while((qzh[j]^qzh[i-1])!=m && j<q.back()){
					j++;
				}
				if((qzh[j]^qzh[i-1])==m) sum++;
			}	
		} 
		else{
			for(int i=x+1,j=x+1;i<=n;i=j){
				while((qzh[j]^qzh[i-1])!=m && j<=n){
					j++;
					//cout<<i<<" "<<j<<" "<<(qzh[j]^qzh[i-1])<<"\n";
				}
				if((qzh[j]^qzh[i-1])==m) sum++;
			}
		}
		
	}
	cout<<sum;
	return 0;
} 
/*
4 0
2 1 0 3
*/