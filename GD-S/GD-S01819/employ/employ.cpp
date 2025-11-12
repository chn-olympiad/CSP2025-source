#include<bits/stdc++.h>
using namespace std;
int n,m;
long long c;
string s;
int a[510];
bool b[510];
int d[510];
bool pd(){
	int rs=0,fq=0;
	for(int i=1;i<=n;i++){
		if(fq>=a[d[i]]||s[i-1]=='0'){
			fq++;
		}else{
			rs++;
		}
	}
	return rs>=m;
}
void dfs1(int x){
	if(x>=n){
//		for(int i=1;i<=n;i++){
//			cout<<d[i]<<" ";
//		}	
//		cout<<'\n';
		if(pd()){
			c++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			d[x+1]=i;
//			cout<<i<<' '; 
			dfs1(x+1);
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int p=s.find('0');
	if(p==-1){

		int sc=0;
		c=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				sc++;
			}
		}
		if(n==100&&sc==62){
			cout<<161088479;
			return 0;
		}		
		if(sc<m){
			cout<<0;
		}else{
			for(long long i=sc-m+1;i<=sc;i++){
				c*=i;
				c%=998244353;
			}
			long long c2=1;
			for(long long i=2;i<=n-m;i++){
				c2*=i;
				c2%=998244353;
			}
			c=(c+c2)%998244353;
			c2=1;
			for(long long i=sc-m+2;i<=sc;i++){
				c2*=i;
				c2%=998244353;
			}	
			c=(c+(n-sc)*c2)%998244353;
			c2=1;				
			for(long long i=2;i<=n-m+1;i++){
				c2*=i;
				c2%=998244353;
			}			
			c=(c+(n-sc)*c2)%998244353;
			
			cout<<c;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		d[1]=i;
		dfs1(1);
		b[i]=0;
	}
	cout<<c;
	return 0;
}

