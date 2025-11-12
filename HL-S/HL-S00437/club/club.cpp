#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int sum = 0;
const int maxn = 2*1e5+10;
struct node{
	int a,b,c;
}s[maxn];
int n;
void dfs(int k);
int a_num,b_num,c_num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		cin>>n;
		ans = 0,sum = 0;
		for(int i = 1; i <= n; i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(int k){
	if(k==n+1){
		ans = max(ans,sum);
		return;
	}
	if(a_num+1<=n/2){
		sum+=s[k].a;
		a_num++;
		dfs(k+1);
		sum-=s[k].a;
		a_num--;
	}if(b_num+1<=n/2){
		sum+=s[k].b;
		b_num++;
		dfs(k+1);
		sum-=s[k].b;
		b_num--;
	}if(c_num+1<=n/2){
		sum+=s[k].c;
		c_num++;
		dfs(k+1);
		sum-=s[k].c;
		c_num--;
	}
}