#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5005];
bool vis[5005];
string s[5005];
struct polygon{
	string in[2005];
	int len;
}t[2005];
void dfs(int u,long long sum,int maxn){
	if(u>n+1){
		return ;
	}
	if(sum>maxn*2&&u-1>=3){
		int too=0;
		bool flag=true;
		for(int i=1;i<=cnt;i++){
			too=0;
			if(u-1!=t[i].len)continue;
			for(int j=1;j<=t[i].len;j++){
				for(int k=1;k<=u-1;k++){
					if(s[k]==t[i].in[j]){
						too++;
						break;
					}
				}
			}
			if(too==u-1)flag=false;
		}
		
		if(flag==true){
			cnt++;
			for(int i=1;i<=u-1;i++){
				t[cnt].in[i]=s[i];
			}
			t[cnt].len=u-1;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			s[u]=to_string(i);
			dfs(u+1,sum+a[i],max(maxn,a[i]));
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<cnt;
	return 0;
}