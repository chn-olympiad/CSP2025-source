#include<bits/stdc++.h>
using namespace std;
long long t,n,a1[1100000],a2[1100000],a3[1100000],v[1100000],ma=-1;
void dfs(int x,int a,int b,int c){
	if(a>n/2 || b>n/2 || c>n/2) return ;
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(v[i]==1) sum+=a1[i];
			else if(v[i]==2) sum+=a2[i];
			else if(v[i]==3) sum+=a3[i];
		}
		if(sum>ma) ma=sum;
		return ; 
	}
	v[x]=1;
	dfs(x+1,a+1,b,c);
	v[x]=2;
	dfs(x+1,a,b+1,c);
	v[x]=3;
	dfs(x+1,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		memset(a1,sizeof(a1),0);
		memset(a2,sizeof(a2),0);
		memset(a3,sizeof(a3),0);
		memset(v,sizeof(v),0);
		for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
		dfs(0,0,0,0);
		cout<<ma<<endl;
		ma=-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
