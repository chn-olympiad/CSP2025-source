#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue> 
#include<vector>
#include<algorithm>
using namespace std;
struct twins{
	int key;
	int value;
};
int a[100000+2][3+2];
twins b[100000+2];
long long best;
int n;
int cmp(twins a,twins b){
	return a.value>b.value;
}
void dfs(int cur,int sum,int x,int y,int z){
	if(cur == n+1){
		if(sum>best)best = sum;
	} 
	for(int i = 1;i<=3;i++){
		if(i == 1&&x+1<=(n/2)){
			dfs(cur+1,sum+a[cur][i],x+1,y,z);
		}
		else if(i == 2&&y+1<=(n/2)){
			dfs(cur+1,sum+a[cur][i],x,y+1,z);
		}
		else if(i == 3&&z+1<=(n/2)){
			dfs(cur+1,sum+a[cur][i],x,y,z+1);
		}
	}
}
priority_queue<int> q;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		cin>>n;
		if(n<200){	
			int sum = 0;
			for(int j = 1;j<=n;j++){
				cin>>a[j][1]>>a[j][2]>>a[j][3];
			}
			dfs(1,0,0,0,0);
			cout<<best<<endl;
			best = 0;
		}
		else {
			int flag  = 0;
			for(int j = 1;j<=n;j++){
				cin>>a[j][1]>>a[j][2]>>a[j][3];
				if(a[j][2] == a[j][3]&&a[j][2]== 0){
					q.push(a[j][1]);
					flag =1;
				}
				else{
					b[j].value = a[j][1]-a[j][2];b[j].key = j; 
				} 
			}
			if(flag){
				int sum = 0;
				for(int j = 0;j<=n/2;j++){
					sum+=q.top();
					q.pop();
				}
				cout<<sum<<endl;
			}
			else{
				int sum;
				sort(b+1,b+1+n,cmp);
				for(int j = 1;j<=(n/2);j++){
					sum+=a[b[j].key][1];
				}
				for(int j = (n/2)+1;j<=n;j++){
					sum+=a[b[j].key][2];
				}
				cout<<sum<<endl;
			}
		} 
	}
	return 0;
}
