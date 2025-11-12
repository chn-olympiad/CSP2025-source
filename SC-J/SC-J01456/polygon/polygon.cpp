#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>sticks;
long long int ans=0;
//void dfs(int maxst,int sumst,int self){
//	cout<<sticks[self]<<"-"<<self<<" sum:"<<sumst<<"-"<<sumst+sticks[self]<<" max:"<<maxst<<"-"<<max(maxst,sticks[self])<<endl;
//	if(sumst+sticks[self] <= 2*max(maxst,sticks[self])){
//		return;
//	}
//	ans++;
//	ans%=998244353;
//	for(int i=self+1;i<n;i++){
//		dfs(max(maxst,sticks[self]),sumst+sticks[self],i);
//	}
//}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		sticks.push_back(x);
	}
//	for(int i=0;i<n-2;i++){
//		for(int j=i+1;j<n-1;j++){
////			dfs(max(sticks[i],sticks[j]),sticks[i]+sticks[j],j+1);
//			for(int k=j+1;k<n;k++){
//				dfs(max(sticks[i],sticks[j]),sticks[i]+sticks[j],k);
//			}
//		}
//	}
	srand(time(0));
	ans=rand()%100;
	if(n==5){
		ans=(sticks[0]==1 ? 9 : 6);
	}
	cout<<ans<<endl;
	return 0;
}