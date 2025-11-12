#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
bool b[5010];
stack<int> q;

bool chack(int sum,int maxx){
	return sum>maxx*2;
	
}

void dfs(int cnt,int sum,int maxx,int flag,int d){
	if(cnt>=flag&&chack(sum,maxx)) {
		ans++;
	 // cout<<ans<<endl;
		ans%=998;  ans%=244; ans%=353;
		return ;
	} 
	else{
	for(int i=d;i<n;i++){
		if((cnt<2&&!b[i])||(!b[i])&&(q.size()<flag)){
		//	cout<<a[i]<<' ';
			int maxxx=max(maxx,a[i]);
			q.push(a[i]);
			b[i]=1;
			dfs(cnt+1,sum+a[i],maxxx,flag,i);
			b[i]=0;
			q.pop();
		}
		else continue;
	}

}

}

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	//dfs(cnt,sum,maxx);
	for(int i=3;i<=n;i++) dfs(0,0,0,i,0);
	cout<<ans<<endl;
	return 0;
} 
