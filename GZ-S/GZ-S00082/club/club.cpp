//GZ-S00082 贵州师范大学云岩实验中学 吴倬然
#include<bits/stdc++.h>
using namespace std;

int f[100005][5],ans,n,t,flag;
void dfs(int i,int a,int b,int c,int cnt){
	if(i==n+1){
		ans=max(ans,cnt);
		return ;
	}
	if(a+1<=n/2){
		dfs(i+1,a+1,b,c,cnt+f[i][1]);
	}
	if(b+1<=n/2){
		dfs(i+1,a,b+1,c,cnt+f[i][2]);	
	}
	if(c+1<=n/2){
		dfs(i+1,a,b,c+1,cnt+f[i][3]);	
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);		
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++){
			cin>>f[i][1]>>f[i][2]>>f[i][3];
			if(f[i][2]!=0||f[i][3]!=0){
				flag=1;
			}
		}
		if(flag==1){
			dfs(1,0,0,0,0);			
		}
		else{
			int a[100005];
			for(int i=1; i<=n; i++){
				a[i]=f[i][1];
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n/2; i++){
				ans+=a[i];
			}		
		}
		cout<<ans<<endl;
	}
return 0; 
}

