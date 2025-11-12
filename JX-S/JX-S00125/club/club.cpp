#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10;

int T,n,fin=0;
struct node{
    int a,b,c;
	bool operator <(const node k)const{
		return a>k.a;
	}
}stu[N];
int dp[N],vis[N];
void dfs(int l,int anum,int bnum,int cnum,int ans){
	if(anum+bnum+cnum==n){
		fin=max(fin,ans);
		return;
	}
	if(anum<n/2) dfs(l+1,anum+1,bnum,cnum,ans+stu[l].a);
	if(bnum<n/2) dfs(l+1,anum,bnum+1,cnum,ans+stu[l].b);
	if(cnum<n/2) dfs(l+1,anum,bnum,cnum+1,ans+stu[l].c);
	
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		fin=0;
		memset(dp,0,sizeof(dp));
        memset(stu,0,sizeof stu);
		cin>>n;
		bool flag=0;
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
			if(stu[i].b || stu[i].c) flag=1;
        }
		if(!flag){
			int ans=0;
			sort(stu+1,stu+n+1);
			for(int i=1;i<=n/2;i++) ans+=stu[i].a;
			cout<<ans;
			return 0;
		}
        dfs(1,0,0,0,0);
        cout<<fin<<"\n";
	}
	
	return 0;
}
