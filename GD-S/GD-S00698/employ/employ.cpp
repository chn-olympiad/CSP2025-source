#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=530,mod=998244353;
int n,m,dif[maxn],man[maxn],ans=0,per[maxn];
bool num[maxn],vis[maxn];
string str;
void dfs(int co,int step){
	per[step]=co;
	num[co]=1;
	if(step==n){
		for(int i=1;i<=n;i++){
			int cd=per[i];
			if(dif[i]==0){
				vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(num[i]==1)continue;
		dfs(i,step+1);
		num[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<n;i++){
		dif[i+1]=str[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>man[i];
	}
	cout<<dif[1];
} 
