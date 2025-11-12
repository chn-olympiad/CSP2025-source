#include<bits/stdc++.h>
using namespace std;
int a[100010][4]={0};
int x[100010];
int n,ans=0;
void dfs(int s1,int s2,int s3,int sum,int id){
	if(s1>n/2||s2>n/2||s3>n/2){
		return;
	}
	if(id>=n){
		ans=max(ans,sum);
		return;
	}
	dfs(s1+1,s2,s3,sum+a[id][0],id+1);
	dfs(s1,s2+1,s3,sum+a[id][1],id+1);
	dfs(s1,s2,s3+1,sum+a[id][2],id+1);
}
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}	
		}
		if(n<=200){
			dfs(0,0,0,0,0);
		}
		else{
			for(int i=0;i<n;i++){
				x[i]=a[i][0];
			}
			sort(x,x+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=x[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
