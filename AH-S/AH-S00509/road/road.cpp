#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
}at[501086];
bool cmp(st xx,st yy){
	return xx.c<yy.c;
}
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>at[i].a>>at[i].b>>at[i].c;
	}
	sort(at+1,at+1+n,cmp);
	for(int i=1;i<m;i++){
		ans+=at[i].c;
	}
	cout<<ans;
	return 0;
}
