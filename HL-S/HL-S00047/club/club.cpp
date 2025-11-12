#include<bits/stdc++.h>
using namespace std;
int n;
int a[100008][5];
int num[5];
int dfs(int x,int l){
	if(x>n){
		return 0;
	}
	int ans=0;
	if(num[l]<n/2){
		num[l]++; 
		ans=max(dfs(x+1,l)+a[x][l],ans);
		num[l]--;
	}
	if(num[(l+1)%3]<n/2){
		num[(l+1)%3]++;
		ans=max(dfs(x+1,(l+1)%3)+a[x][(l+1)%3],ans);
		num[(l+1)%3]--;
	}
	if(num[(l+2)%3]<n/2){
		num[(l+2)%3]++;
		ans=max(dfs(x+1,(l+2)%3)+a[x][(l+2)%3],ans); 
		num[(l+2)%3]--;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2]; 
		}
		cout<<dfs(1,1)<<endl;
	}
	return 0;
}

