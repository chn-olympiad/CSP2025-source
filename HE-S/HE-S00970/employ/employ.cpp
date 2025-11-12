#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[10010],ans,sum,v[1010],c[1010],qw,deep;
vector<int> q[1010];
void dfs(int dep,int give,int ach){
	if(give+m>n) return ;
	if(dep>n){
		if(ach>=m) sum++;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(a[dep]==1){
			if(v[i]==0 and give<b[i]){
				v[i]=1;
				dfs(dep+1,give,ach+1);
				v[i]=0;
			}else if(v[i]==0){
				v[i]=1;
				dfs(dep+1,give+1,ach);
				v[i]=0;
			}
		}else{
			if(v[i]==0){
				v[i]=1;
				dfs(dep+1,give+1,ach);
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("emplot.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='1'){
			a[i]=1;
			ans++;
		}
		
	}
	
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0) qw++;
	}
	if((n-ans)+m>n){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(ans!=n){
			cout<<0;
			return 0;
		}else if(qw!=0){
			cout<<0;
			return 0;
		}
		deep=1;
		for(int i=1;i<=n;i++){
			deep*=i;
			deep%=998244353;
		}
		return 0;
	}
	if(ans==n){
		sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	
	dfs(1,0,0);
	cout<<sum;
}
