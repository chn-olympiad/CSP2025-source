#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int n,ans;
int a[N];
void dfs(int gg,int k,int last,int sum,int ma){
	if(k>=gg){
		if(sum>2*ma)	ans++;
		return;
	}
	//cout<<last<<endl;
	for(int i=last+1;i<=n;i++)
		dfs(gg,k+1,i,sum+a[i],max(ma,a[i]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	if(n<3){cout<<0;return 0;}
	for(int i=1;i<=n;i++)	scanf("%d",a+i);
	for(int i=3;i<=n;i++)
		dfs(i,0,0,0,0);
	printf("%d",ans);
	return 0;
}
