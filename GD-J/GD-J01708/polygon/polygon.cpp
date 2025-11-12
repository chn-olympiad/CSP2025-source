#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],cnt;
void dfs(int dep,int sum,int maxn,int num,int i){
	if(dep==n){
	    if(num==i){
	    	if(sum>maxn*2){
	    		cnt++;
	    		cnt+=mod;
	    		cnt%=mod;
			}
		}
		return ;	
	}
	dfs(dep+1,sum+a[dep],max(maxn,a[dep]),num+1,i);
	dfs(dep+1,sum,maxn,num,i);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//CCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCF
	/*가가가가가가가가가가가가가가가가
	가가가가가가가가가가가가가가가가가가가가
	가가가가가가가가가가가가가가가가가가가가가가가가가가가
	가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가
	가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가
	쏟쾨怜唐200뜩죄T3等척컸척켜？？？？ 가가가가가가가가가가가가가*/ 
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,0,0,i);
	}
	cout<<cnt;
	return 0;
} 
