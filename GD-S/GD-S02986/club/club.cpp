#include<iostream>
#include<algorithm> 
using namespace std;
const int N=1e5+3;
int a[N],b[N],c[N];
int dp[N];
int n,ans;
int s[100003];

void dfs(int cur){
	if(cur==n+1){
		int sum=0;
		int an=n/2;
		int bn=n/2;
		int cn=n/2;
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				an--;
				sum+=a[i];
			}else if(s[i]==2){
				bn--;
				sum+=b[i];
			}else{
				cn--;
				sum+=c[i];
			}
			if(an<0 || bn<0 || cn<0){
				flag=true;
				break;
			}
		}
		if(!flag) ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		s[cur]=i;
		dfs(cur+1);
	}
}
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool flag=false;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0) flag=true;
		}
		if(n<=9){
			dfs(1);
			cout<<ans<<'\n';
		}else if(!flag){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]>b[i] && a[i]>c[i]) sum+=a[i];
				else if(b[i]>a[i] && b[i]>c[i]) sum+=b[i];
				else sum+=c[i];
			}
			cout<<sum;
		}else{
			sort(a+1,a+n+1,cmp);
			cout<<a[1]+a[2]<<'\n';
		}
	}
}
