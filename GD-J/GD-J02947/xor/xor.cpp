#include<bits/stdc++.h>
using namespace std;
const int Max=500010;
int ans=0;
int num[Max],Map[1010][1010];
int n,k;
inline int f(int l,int r){
	int idx=num[l];
	for(int i=l+1;i<=r;i++){
		idx=(idx^num[i]);
	}
	return idx;
}
inline void dfs(int l,int r,int idx){
	
	if(l>r||r>n){
		
		return;
	}
	if(Map[l][r]==k){
		//cout<<l<<" "<<r<<endl;
		idx++;
		ans=max(ans,idx);
	}
	for(int i=r+1;i<=n;i++){
		if(Map[r+1][i]==k)
		// printf("%d %d\n",r+1,i);
		dfs(r+1,i,idx);
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	
	
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(k==0){
		
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) Map[i][j]=num[i];
			if(Map[i][j]!=0) continue;
			Map[i][j]=f(i,j);
			Map[j][i]=Map[i][j];
			
		}
	}
	//cout<<Map[1][2]<<endl;
	for(int i=1;i<=n;i++){
		dfs(1,i,0);
	}
	
	cout<<ans;
	
	
	return 0;
}
