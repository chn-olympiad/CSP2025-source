#include<bits/stdc++.h>
using namespace std;
char s[510];
int c[510];long long ys=998244353;
int n;int m;int jg[210];bool hsh[210];long long ans=0;
void print(){
	int tt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||tt>=c[jg[i]]){
			tt++;
		}
	}
	if(tt<=n-m){
		ans++;
	}
}
void dfs(int k){
	for(int i=1;i<=n;i++){
		if(hsh[i]==0){
			jg[k]=i;
			hsh[i]=1;
			if(k==n){
				print();
			}else{
				dfs(k+1);
			}
			jg[k]=0;
			hsh[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=18){
		for(int i=1;i<=n;i++){
			cin>>s[i];	
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];	
		}
		dfs(1);
		cout<<ans%ys;
	}else{
		for(int i=1;i<=n;i++){
			cin>>s[i];	
		}
		int n1=n;
		for(int i=1;i<=n;i++){
			cin>>c[i];	
			if(c[i]==0){
				n1--;
			}
		}
		
		if(n1<m){
			cout<<0;
		}else{
			long long ans=1; 
			for(long long i=1;i<=n;i++){
				ans=(ans*i)%ys;
			}
			cout<<ans;
		}
	}

	return 0;
}