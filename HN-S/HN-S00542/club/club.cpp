#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int const N =1e5+100;
struct jgt{
	int x,st,my;
}e[N];
int x[N],st[N];
bool cmp(jgt a,jgt b){
	return a.my>b.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int a=0,ans=0;
		for(int i=1;i<=3*n;i++){
			st[i]=0;
			x[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[++a].my;
				e[a].x=i;
				e[a].st=j;
			}
		}
		sort(e+1,e+3*n+1,cmp);
		for(int i=1;i<=3*n;i++){
			if(x[e[i].x]) continue;
			if(st[e[i].st]+1>n/2) continue;
			cout<<st[2]<<" ";
			ans+=e[i].my;
			x[e[i].x]=1;
			st[e[i].st]++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

