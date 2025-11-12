#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
int ans=0;
int p[1000020]={0}; 
struct node{
	int a,b,c,id;
}e[10000000];
bool cmp(node aa,node bb){
	return aa.a>bb.a;
}
void dfs(int k,int o,int t,int tr){
	if(k>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				sum+=e[i].a;
			}
			else if(p[i]==2){
				sum+=e[i].b;
			} 
			else{
				sum+=e[i].c;
			}
		}
		ans=max(ans,sum);
		return ;
	}
	if((o+1)<=n/2){
		p[k]=1;
		dfs(k+1,o+1,t,tr);
		p[k]=0;
	}
	if((t+1)<=n/2){
		p[k]=2;
		dfs(k+1,o,t+1,tr);
		p[k]=0;
	}
	if((tr+1)<=n/2){
		p[k]=3;
		dfs(k+1,o,t,tr+1);
		p[k]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int f=1;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			e[i].id=i;
			if(e[i].b!=0&&e[i].c!=0){
				f=0;
			}
		}
		if(f){
			sort(e+1,e+1+n,cmp);
			int w=0;
			for(int i=1;i<=n;i++){
				w+=1;
				ans+=e[i].a;
				if(w>n/2){
					cout<<ans<<"\n";
					break;
				} 
			}
		}
		else{
			ans=0;
			dfs(1,0,0,0);
			cout<<ans<<"\n";		
		}

	}
	return 0;
} 
