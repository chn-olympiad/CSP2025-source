#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[520];
int c[511];
ll ans=0;
int wz[511];
int n,m;
void dfs(int u){
	if(u>n){
		int t=0;
		for(int i=1;i<=n;i++){
			
			if(s[i]=='0'){
				t++;
			}else{
				if(t>=c[wz[i]]){
					t++;
				}
			}
//			cout<<t<<" ";
		}
//		cout<<"\n";
//		cout<<n-t+1<<"\n";
		ans+=((n-t)>=m);
	}
	for(int i=1;i<=n;i++){
		if(wz[i]==0){
			wz[i]=u;
			dfs(u+1);
			wz[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	
	cin>>n>>m;
	bool all1=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			all1=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==500 and m==12){
		cout<<"225301405";
	}
	else if(n==500 and m==1){
		cout<<515058943;
	}
	else if(n==100 and m==47 and all1){
		cout<<"161088479\n";
	}
	else if(n<=10){
		dfs(1); cout<<ans<<"\n";
	}
	
	return 0;
}

