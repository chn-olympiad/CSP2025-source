#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ma=-2e18;
struct R{
	int id,a,b,c;
}a[100010];
void dfs(int al,int bl,int cl,long long sum,int cs){
	if(al+bl+cl==n)ma=max(ma,sum);
	if(al<n/2)dfs(al+1,bl,cl,sum+a[cs].a,cs+1);
	if(bl<n/2)dfs(al,bl+1,cl,sum+a[cs].b,cs+1);
	if(cl<n/2)dfs(al,bl,cl+1,sum+a[cs].c,cs+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long sum=0;
		ma=-2e18;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(1,0,0,sum+a[0].a,1);
		dfs(0,1,0,sum+a[0].b,1);
		dfs(0,0,1,sum+a[0].c,1);
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
