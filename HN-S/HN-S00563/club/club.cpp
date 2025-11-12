#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int t,a[N][5],b[N][5],n,ans,cnt,f[5],l,s[N];
int check(){
	int mp[5]={0,0,0,0,0};
	for(int i=1;i<=n;i++){
		mp[s[i]]++;
	}
	for(int i=1;i<=3;i++){
		if(mp[i]>n/2){
			return 0;
		}
	}
	return 1;
}
void dfs(int x,int y){
	if(x>n){
		if(check()){
			for(int i=1;i<=n;i++){
				cnt+=a[i][s[i]];
//				cout<<s[i]<<" ";
			}
//			cout<<cnt<<endl;
			ans=max(ans,cnt);
			cnt=0;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		s[x]=i;
		dfs(x+1,i);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,cnt=0;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++){
			dfs(1,i);
//			fill(s+1,s+n+1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
