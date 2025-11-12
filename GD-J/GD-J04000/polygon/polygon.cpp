#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[5005];
int vis[5005];
int choose[5005];
int ans;
int nc;

bool check(){
	int maxs = 0;
	int sum = 0;
	for(int i = 1;i<=nc;i++){
		maxs = max(maxs,choose[i]);
		sum += choose[i];
	}
	if(sum>(2*maxs))return 1;
	else return 0;
}

void DFS(int nk,int k,int last_choose_id){
	if(nk>=k){
		if(check()){
			ans++;
			return;
		}
	}
	for(int i = last_choose_id+1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		choose[++nc] = a[i];
		vis[i] = 1;
		DFS(nk+1,k,i);
		vis[i] = 0;
		nc--;
	}
}

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 3;i<=n;i++){
		DFS(0,i,0);
	}
	cout<<ans;
	return 0;
} 
