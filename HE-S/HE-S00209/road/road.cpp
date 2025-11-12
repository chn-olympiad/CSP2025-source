#include<bits/stdc++.h>
using namespace std;
int a[100010];
int a1[100010];
int b[100010];
int c[100010];
bool cmp(int ae,int be){
	return ae>be;
}int n;
int fan[100010];
long long maxan;
void dfs(int dee,int ja,int jb,int jc){
	if(dee>n){
		long long ans=0;
		for(int i=1; i<=n; i++){
			if(fan[i]==1){
				ans+=a[i];
			}else{
				if(fan[i]==2){
					ans+=b[i];
				}else{
					ans+=c[i];
				}
			}
		}
		maxan=max(ans,maxan);
		return ;
	}
	if(ja>n/2 || jb>n/2 || jc>n/2){
		return ;
	}
	if(ja<n/2 ){
		fan[dee]=1;
		dfs(dee+1,ja+1,jb,jc);
		fan[dee]=0;	
	}
	if(jb<n/2){
		fan[dee]=2;
		dfs(dee+1,ja,jb+1,jc);
		fan[dee]=0;
	}
	if(jc<n/2){
		fan[dee]=3;
		dfs(dee+1,ja,jb,jc+1);
		fan[dee]=0;		
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=1; i<=100010; i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
			a1[i]=0;
			fan[i]=0;
		}
		maxan=0;
		cin>>n;
		int flag=0;
		for(int i=1; i<=n; i++){
			cin>>a[i]>>b[i]>>c[i];
			a1[i]=a[i];
			if(b[i]!=0 || c[i]!=0){
				flag=1;
			}
		}
		if(flag==0){
			sort(a1+1,a1+1+n,cmp);
			long long ans=0;
			for(int i=1; i<=n/2; i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}else{
				dfs(1,0,0,0);
				cout<<maxan<<endl;	
		}
	}
	return 0;
}
