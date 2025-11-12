#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long sum=0,suum;
int vis[25];
int jl[10005];
int a[10005];
int z=1;
void solve(int x) {
	vis[x]=1;
	if(z==n+1){
		int cnt=0;
		int sbdr=0;
		for(int i=1;i<z;i++){
			if(s[i-1]=='0'||sbdr>=a[jl[i]]){
				sbdr++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m){
			sum++;
			sum%=998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			jl[z]=i;
			z++;
		    solve(i);
		    vis[i]=0; 
		    z--;
	    }
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		solve(0);
		cout<<sum;
	}
	else{
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	if(m==1){
	suum=1;
		for(int i=n;i>=1;i--){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
