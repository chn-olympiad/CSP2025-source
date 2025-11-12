#include<bits/stdc++.h>
using namespace std;
long long a[5005],most,ans,anser,c,n,an[5005];
void dfs(int b,int m){
	if(c==m){
		if(ans>most*2){
			anser++;
		}
		return ;
	}
	for(int i=b;i<=n;i++){
		ans+=a[i];
		c++;
		an[c]=i;
		if(i>most){
			most=i;
		}
		dfs(i+1,m);
		c--;
		ans-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		c=0;
		ans=0;
		most=0;
		dfs(1,i);
	}
	cout<<anser;

	return 0;
}

