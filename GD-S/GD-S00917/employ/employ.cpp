#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
bool b[1005],used[1005];
int c[1005],list[1005];
int ans=0;
int n,m;
bool check(){
	int cnt=0,num=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0)cnt++;
		else if(cnt>=c[list[i]])cnt++;
		else num++;
	}
	return num>=m;
}
void dfs(int x){
	if(x>n){
		if(check())ans++;;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			list[x]=i;
			used[i]=1;
			dfs(x+1);
			used[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		b[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
}
