#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>a;
int b[500010],mx=0;
void dfs(int f,int n,int prev,int num){
	if(f==n){
		mx=max(mx,num);
		return;
	}
	dfs(f+1,n,prev,num);
	if(prev==-1||a[f].first>a[prev].second){
		dfs(f+1,n,f,num+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=i;j<=n;j++){
			res=res^b[j];
			if(res==k){
				a.emplace_back(i,j);
			}
		}
	}
	dfs(0,a.size(),-1,0);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}