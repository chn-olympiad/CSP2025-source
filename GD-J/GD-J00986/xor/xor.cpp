#include<bits/stdc++.h>
using namespace std;
int n,k,ans,temp;
bool vis[long(5*10e5)];
vector<int> num;
int sum(int b,int e){
	int t=num[b];
	
	for(int i=max(b+1,e);i<=e;i++){
		t^=num[i];
	}
	return t;
}
bool detect(int b,int e){
	for(int i=b;i<=e;i++){
		if(vis[i]) return 0;
	}
	return 1;
}
void fil(int b,int e){
	for(int i=b;i<=e;i++){
		vis[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>temp;
		num.push_back(temp);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(sum(i,j)==k and detect(i,j)){
				ans++;
//				cout<<i<<' '<<j<<' '<<sum(i,j)<<'\n';
				fil(i,j);
			}
		}
	}
	cout<<ans;
} 
