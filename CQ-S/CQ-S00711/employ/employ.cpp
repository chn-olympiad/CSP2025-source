#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int Mod=998244353;
int n,m;
int c[N];
char a[N];
int vis[N]; 
long long cnt; 
int yj;
void bl(int x,int p,int cs){
	if(c[x]<=p) p+=1 ;
	else if(a[cs-1]=='0') p+=1;
	vis[x]=1;
	if(n-p<m) return ; 
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			int y=cs+1;
			bl(i,p,y);
			
			vis[i]=0;
		}
	}
	if(cs==n) cnt+=1;
	cnt%=Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='1') yj+=1;
	}
	if(yj==n) {
		int sum=0;
		long long s=0;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]!=0) sum+=1;
		}
		for(int i=1;i<=sum;i++){
			if(i==1) s=i;
			else s*=i;
			s%=Mod;
		}
		cout<<s;
		return 0;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		long long s=1;
		for(int i=1;i<=n;i++){
			s*=i;
			s%=Mod;
		}
		cout<<s;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
	}
	
	c[0]=2e5;
	a[-1]='1';
	bl(0,0,0);// ren pause site
	cout<<cnt%Mod;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

