#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	vector<int>P(n);
	int minn=2;
	for(int &p:P)cin>>p,minn=min(minn,p);
	if(minn==1){	//性质A
		if(k==0)return cout<<n/2,0;
		if(k==1)return cout<<n,0;
	}
	if(minn==0){	//性质B
		if(k==0){
			int ans=(P[0]==0);
			for(int i=1;i<n;i++){
				if(P[i]==0)ans++,P[i]=2;
				if(P[i]==1&&P[i-1]==1)ans++,P[i]=P[i-1]=2;
			}
			return cout<<ans,0;
		}
		if(k==1){
			int ans=0;
			for(int p:P)if(p==1)ans++;
			return cout<<ans,0;
		}
	}
	cout<<n/2;
	return 0;
}//A,B30+