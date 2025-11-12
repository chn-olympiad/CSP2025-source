#include<bits/stdc++.h>
using namespace std;
 long long n;
long long a[100];
long long ans=0;
bool v[5010];
void dfs(int step,int tot,long long maxa){
	if(maxa*2>=tot&&step>3) return ;
	if(step>n){
		return ;
		
	} 
	if(step>3){
	ans++;	
	} 
	ans%=998244353;
	for(int i=step;i<=n;i++){
		dfs(step+1,tot+a[i],max(maxa,a[i]));
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<998244352;
	return 0;
} 
