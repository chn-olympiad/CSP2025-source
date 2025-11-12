#include<bits/stdc++.h>
using namespace std;
#define int long long
int nn;
int a[5005];
const int MOD=998244353;
int dp[5005][2005];
int sum;
struct Node{
	int n,choice,len,sum,max;
};
queue <Node> q;
void bfs(){
	while(!q.empty()){
		Node temp = q.front();
		
		q.pop();
		if(temp.max*2<temp.sum&&temp.len>=3&&temp.choice!=0){
		//	cout<<temp.n<<" "<<temp.max<<" "<<temp.sum<<" "<<temp.choice<<" "<<temp.len<<endl; 
			sum=(sum+1)%MOD;
		} 
		if(temp.n+1<=nn){
			
		
			q.push({temp.n+1,0,temp.len,temp.sum,temp.max});
			q.push({temp.n+1,1,temp.len+1,temp.sum+a[temp.n+1],a[temp.n+1]});
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>nn;
	for(int i=1;i<=nn;i++){
		cin>>a[i];
	}
	sort(a+1,a+nn+1);
	q.push({1,1,1,a[1],a[1]});
	q.push({1,0,0,0,0});
	bfs();
	cout<<sum<<endl;
	return 0;
} 
