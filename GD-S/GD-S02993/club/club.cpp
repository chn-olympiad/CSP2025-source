#include<bits/stdc++.h>
using namespace std; 
#define Max 1005
#define ll long long
ll n,a[Max][10];
ll num[10];
int ans=0;
void dfs(int m,int old){
	for(int i=m;i<=n;i++){
		for(int j=1;j<=3;j++){
			num[j]++;
			if(num[j]<=n/2) dfs(i+1,old+a[i][j]),num[j]--;
				else	num[j]--;	
		}
	}
	if(m>n){
		ans=max(ans,old);
		 return ;
	}
}
void cler(){
	ans=0;
	for(int i=0;i<=Max;i++)
		for(int j=0;j<5;j++)
			num[j]=0,a[i][j]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
int t=0;
cin>>t;
while(t){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j]; 
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	cler();
	t--;
}
	
	
	return 0;
}

