#include<bits/stdc++.h>
using namespace std;
int n,m,out=0;
string difficult;
vector<int>have_gone;
vector<bool>is_choose;
void dfs(int deep,int is_have,int is_die){
	if(deep>=n){
		if(is_have>=m){
			//all right
			out++;
			out%=998244353;
			return;
		}
		return;
	}
	if(is_have>=m){
		//cut
		int mul=1;
		for(int i=n-deep;i>1;i--){
			//1==1;2==2;3==6....
			mul*=i;
			mul%=998244353;
		}
		out+=mul;
		return;
	}
	for(int i=0;i<n;i++){
		if(!is_choose[i]){
			is_choose[i]=1;
			if(is_die<have_gone[i]&&(difficult[deep]=='1'))dfs(deep+1,is_have+1,is_die);
			else dfs(deep+1,is_have,is_die+1);
			is_choose[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	have_gone.resize(n);
	is_choose.clear();
	is_choose.resize(n,false);
	cin>>difficult;
	for(int i=0;i<n;i++)cin>>have_gone[i];
	sort(have_gone.begin(),have_gone.end(),greater<int>());
	dfs(0,0,0);
	cout<<out;
	return 0;
}

