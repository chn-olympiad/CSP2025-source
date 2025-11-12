#include<bits/stdc++.h>
using namespace std;
int n,k;
int len[500005];
bool vis[500005];
int yiho(int a,int y){
	bool xl[100]={0};
	bool yl[100]={0};
	int xid=1;
	int yid=1;
	while(a>0){
		if(a&1)xl[xid]=1;
		a/=2;
		xid++;
	}
	while(y>0){
		if(y&1)yl[yid]=1;
		y/=2;
		yid++;
	}
	int num=0;
	long long p=1;
	for(int i=1;i<max(xid,yid);i++){
		if(yl[i]!=xl[i]){
			num+=p;
		}
		p*=2;
	}
	return num;
}
bool is(int x,int y){
	int ans=len[x];
	if(vis[x])return 0;
	for(int i=x+1;i<=y;i++){
		if(vis[i])return 0;
		ans=yiho(len[i],ans);
		
	}
	if(ans==k)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>len[i];
	}
	long long ans=0;
	for(int s=1;s<=n;){
		for(int i=1,j=s;j<=n;i++,j++){
			if(is(i,j)){
				ans++;
				for(int k=i;k<=j;k++)vis[k]=1;
			}
		}
		int mns=n+1;
		int blon=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])blon++;
			else{
				blon=0;
			}
			if(blon>s&&blon<mns)mns=blon;
		}	
		if(mns==n+1)break;
		s=mns;
		//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
		//cout<<endl;
	}
	//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
	cout<<ans;
	return 0;
}
