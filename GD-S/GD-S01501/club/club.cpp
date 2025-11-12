#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5+2;
int T;
int a[maxn][4];
int c[maxn];
int f[4];
int n;
int ans=-1;
int minx;
bool a2,a3; 

//i-clubs
//j-persons
void dfs(int i,int j,int sum){
		
	if(j>n){
		
		ans=max(ans,sum);
		return;
		
	}
	
	for(i=1;i<=3;i++){
		
		if(f[i]<minx){
			
			f[i]++;
			dfs(i,j+1,sum+a[j][i]);
			f[i]--;
			
		}
		
	}
	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>T;
	while(T--){
		
		memset(f,0,sizeof f);
		memset(a,0,sizeof a);
		minx=0,ans=-1;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2 and a[i][j]>0) a2=true;
				if(j==3 and a[i][j]>0) a3=true;
			}
		}
		
		minx=n/2;
		
		if(a2==false and a3==false){
			
			int sum_s=0;
			
			for(int i=1;i<=n;i++){
				
				c[i]=a[i][1];
				
			}
			sort(c+1,c+n+1);
			for(int i=(n-minx+1);i<=n;i++) sum_s+=c[i];
			cout<<sum_s<<endl;
			return 0;
			
		}
		
		dfs(1,1,0);
		
		cout<<ans<<endl;
		
	}
	
	return 0;
	
} 
