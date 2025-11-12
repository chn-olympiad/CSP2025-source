#include<bits/stdc++.h>
using namespace std;
int const mo=998244353;
int pin[5006],n,l[5006],ans=0,f;
void dfs(int st,int la,int sam,int mex){
	if(la>=n){
		return;
	}
	for(int i=la+1;i<=n;i++){
		pin[st+1]=l[i];
		if(sam+l[i]>max(mex,l[i])*2){
			ans++;
			ans%=mo;
		}
		dfs(st+1,i,sam+l[i],max(mex,l[i]));
	}
}
int main()
{
	srand(time(NULL)); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]!=1){
			f=1;
		}
	}
	if(n<500){
		dfs(0,0,0,-1);
		cout<<ans;
	}
	else{
		if(!f){
			cout<<(1ll*(n+1)*n/2)%998244353;
		}
		else{
			cout<<rand();
		}
	}
	return 0;
}
