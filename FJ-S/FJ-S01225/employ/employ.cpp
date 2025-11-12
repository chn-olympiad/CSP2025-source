# include <bits/stdc++.h>
using namespace std;
long long int n,m,ans=0;
string s;
bool v[100086];
long long  cc[100086],path[100086];
void dfs(int c,int hh){
	if(c>hh){
		int wl=0,rs=0;
		for(int q=1;q<=hh;q++){
			
			if(wl>=path[q]) wl++;
			else if(s[q-1]=='1'){
				rs++;
			}
			else if(s[q-1]=='0')wl++;
			if(rs>=m) {
				ans++;
				break ;
			}
			
		}
		
	}else{
		for(int q=1;q<=n;q++){
			if(v[q]!=1){
				v[q]=1;
				path[c]=cc[q];
				dfs(c+1,hh);
				v[q]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int ss=0;
	for(int q=1;q<=n;q++){
		cin>>cc[q];
		if(s[q-1]=='1') ss++;
	}
	if(m==n){
		if(ss==n)cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	if(ss==n){
		ans=1;
		for(int q=m;q<=n;q++){
			ans*=q;
		}
		
		cout<<ans<<endl;return 0;
	}
	if(ss==0){
		cout<<"0"<<endl;return 0;
	}
	dfs(1,n);
	ans=ans%(long long)998244353;
	cout<<ans<<endl;
}
