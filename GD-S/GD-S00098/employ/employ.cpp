#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
template<class...Arg>
void println(Arg...arg){
	int _[]={(cout<<arg<<' ',0)...};
	cout<<'\n';
}
int n,m;
string diff;
int ff=0;
int nn[505];
bool use[505];
void dfs(int x,vector<int>& lst){
	if(x==n+1){
		int tot=0,ans=0;
		for(int i=0;i<n;i++){
			if(tot>=lst[i]){
				++tot;
				continue;
			}
			
			if(diff[i]=='1'){
				++ans;
			}else ++tot;
			//println("test",diff[i],ans,tot,i,lst[i]);
		}
//		for(int i=0;i<lst.size();i++){
//			cout<<lst[i]<<' ';
//			}
//			cout<<(tot>=m?"ok":"no")<<'\n';
		if(ans>=m){
			++ff;
			
		}
	}
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		use[i]=true;
		lst.push_back(nn[i]);
		dfs(x+1,lst);
		lst.pop_back();
		use[i]=false;
	}
}
int main(){
	//freopen("../../csps/employ/employ3.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>diff;
	for(int i=1;i<=n;i++){
		cin>>nn[i];
	}
	vector<int> lst;
	dfs(1,lst);
	cout<<ff;
	return 0;
}
