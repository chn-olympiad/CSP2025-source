#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void DFS(int x,int g,long long m,long long w){
	if(x>n){
		return ;
	}
	if(g>=3&&m*2<w)ans++;
	for(int i=x;i<=n;i++)DFS(i+1,g+1,max(m,a[i+1]),a[i+1]+w); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)DFS(i,1,a[i],a[i]);
	cout<<ans;
}
