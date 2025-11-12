#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[500+10];
int c[500+10]; 
int hsh[500+10]; 
long long num=0;
void dfs(int k,int out,int in){
	for(int i=1; i<=n; i++){
		if(hsh[i]==0){
			if(c[i]>out&&s[k]=='1'){
				hsh[i]=1;
				in++;
				if(k==n&&in>=m){
					num++;
				}
				//cout<<k<<" "<<in<<" "<<out<<" "<<i<<endl;
				dfs(k+1,out,in);
				hsh[i]=0;
				in--;
			}else if(c[i]<=out||s[k]=='0'){
				hsh[i]=1;
				out++;
				if(k==n&&in>=m){
					num++;
				}
				//cout<<k<<" "<<in<<" "<<out<<" "<<i<<endl;
				dfs(k+1,out,in);
				hsh[i]=0;
				out--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<num%998244353;
	return 0;
}
