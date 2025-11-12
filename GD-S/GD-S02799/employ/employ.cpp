#include<bits/stdc++.h>
using namespace std;
string s;
int c[1005];
bool vis[1005];
long long ans;	
int n,m;
long long pai(int q){
	long long an=1;
	for(int i=q;i>0;i--){
		an*=i;
		an%=998244353;
	} 
	return an;
}
void dfs(int lu,int cen){
	if(lu>=m&&cen==n){
		ans++;	
		ans%=998244353;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(s[cen]=='1'){
				if(cen-lu+1>c[i]){
					vis[i]=true;
					dfs(lu,cen+1);
					vis[i]=false;
				}
				else{
					vis[i]=true;
					dfs(lu+1,cen+1);
					vis[i]=false;
				}
			}
			else{
				vis[i]=true;
				dfs(lu,cen+1);
				vis[i]=false;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cntz=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0)cntz++;
	}
	bool isA=true;
	int kk=-1;
	int fir=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			isA=false;
			break;
		}
		else if(kk==-1){
			kk=0;
			fir=i;
		}
	}
	if(n==m){
		if(!isA){
			cout<<0;
		}
		else{
			cout<<pai(n);
		}
		return 0;
	} 
	if(kk==-1)ans=0;
	else if(m==1){
		sort(c,c+n);
		int w=upper_bound(c,c+n,fir)-c;
		if(w!=n){
			cout<<1ll*(n-w)*pai(n-1)%998244353;
			return 0;
		}
	}
	else if(isA){
		if(n-cntz<m){
			ans=0;
		}
		else{
			int quan=n-cntz;
			ans=pai(quan);
		} 
	}
	else if(n<=18){
		dfs(0,0);	
	}
	cout<<ans;
}
