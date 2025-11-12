#include<bits/stdc++.h>

using namespace std;
#define r(i,a,b) for(int i=a;i<=b;i++)
int n,a[1010],sum,emp,le,u;
string b;
inline void dfs(int x){
	if(emp>=le){
		sum++;
		return;
		}
	while(b[u]=='1'||b[u]=='0'){
		u++;
		if(x>=a[u]&&b[x]=='1'){
			dfs(x+1);
			}
		else{
			r(i,1,n) if(a[i]>x) emp++;		
			}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&le);
	cin>>b;
	r(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(0);
	cout<<sum;
}
