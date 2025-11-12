#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
int n,a[5009],cnt=0;
const int mod=998244353;
void dfs(int x,int sum,int last_choose){
	if(x==n+1){
		if(sum==0)return;
		if(last_choose>=sum-last_choose)return;
		cnt=(cnt+1)%mod;
	}else{
		dfs(x+1,sum+a[x],a[x]);//choose
		dfs(x+1,sum,last_choose);//not choose
	}
}
int main(){
	//Force!! 40pts
	//war god bless me!
	fropen("polygon");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
