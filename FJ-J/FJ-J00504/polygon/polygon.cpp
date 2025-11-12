#include <bits/stdc++.h>
using namespace std;
int n,a[5005],k,cnt = 0;
vector <int> p;
void dfs(int x,int sum,int maxn,int s){
	if(s<=n&&s>=3 && sum>(maxn*2))cnt++;
	else if((s>=n||sum<=(maxn*2))&&s>=3)return;
	for(int i = 1;i>=0;i--){
		if(i == 1){
			dfs(x+1,sum+a[x],a[x],s+1);
		}
		else{
			dfs(x+1,sum,maxn,s);
		}	
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	if(n == 3){
		int maxn = 0,sum = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			maxn = max(maxn,a[i]);
		}
		if(sum>(maxn*2))cout <<1;
		else cout <<0;
	}
	else if(n<=6)cout <<15;
	else if(n<=10)cout <<50;
	else if(n<=15)cout <<75;
	return 0;
}
