#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int xiaop[maxn][3];

int n,ans;
void dfs(int A,int B,int C,int sum,int nowi){
//	cout<<A<<' '<<B<<' '<<C<<endl;
	if(A>n/2||B>n/2||C>n/2){
		return;
	}
	if(nowi>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=0;i<3;i++){
		if(i==0){
			A++;
		}else if(i==1){
			B++;
		}else{
			C++;
		}
		dfs(A,B,C,sum+xiaop[nowi][i],nowi+1);
		if(i==0){
			A--;
		}else if(i==1){
			B--;
		}else{
			C--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(;T;T--){
		cin>>n;
		memset(xiaop,0,sizeof xiaop);
		int aa=0;
		for(int i=1;i<=n;i++){
			cin>>xiaop[i][0]>>xiaop[i][1]>>xiaop[i][2];
			if(xiaop[i][1]==xiaop[i][2]&&xiaop[i][1]==0){
				aa++;
			}
		}
		ans=0;
		if(aa==n){
			priority_queue<int> q;
			for(int i=1;i<=n;i++){
				q.push(xiaop[i][0]);
			}
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}else{
			dfs(0,0,0,0,1);			
		}

		cout<<ans<<'\n';
	}
	return 0;
}
