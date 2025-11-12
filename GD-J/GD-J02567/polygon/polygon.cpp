#include<bits/stdc++.h>
using namespace std;
int n,f[11000],b[11000];
long long k=0;
void dfs(int c,int ma,int ans,int q){
	if(ans>2*ma and c>=3){
		k++;
		k%=998244353;
		//cout<<'-'<<s<<endl;
	}
	if(c==5) return ; 
	for(int i=q+1;i<=n;i++){
		/*if(c==n-1 and (ans+f[i])>2*f[i] and c>=3){
			k++;
		}*/
		//else{
			dfs(c+1,f[i],ans+f[i],i);
			
		//}
	}
	//cout<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	dfs(0,-1,0,0);
	cout<<k%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
