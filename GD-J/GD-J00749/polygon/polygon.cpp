#include<bits/stdc++.h>
using namespace std;


int he[6000];
int num[6000];
int n;
bool b[6000];
int ans=0;

void dfs(int x,int cnt,int k){
	for(int i=x+1;i<=n;i++){
		if(!b[i]){
			b[i]=true;
			if(cnt>num[i]){
				ans++;
				ans%=998244353;  
			}
			dfs(i,cnt+num[i],k+1);
			b[i]=false;
		}
	}
	return ; 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		he[i]=he[i-1]+num[i];	
	}
	dfs(0,0,1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
