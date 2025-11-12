#include<bits/stdc++.h>                        
using namespace std;
struct node{
	int id;
	int s;
	int x;
};
int t,n;
node a[1000]={};
bool flay[1000]={};
bool cmp(node x,node y){
	return x.s >y.s;
}
int f(int x,int y int z){
	memset(flay ,0,sizeof(flay));
	int g[4]={};
	for(int i=1;i<=3*n;++i){
		if(a[i].id==x && g[a[i].id]<l && flay[a[i].x]){
			g[a[i].id]++;
			ans += a[i].s;
			flay[a[i].x]
		}
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(flay, 0 , sizeof(flay));
		int temp=1;
		cin>>n;
		int l=n/2;
		for(int i=1;i<=n;++i){
			
			
			for(int j=1;j<=3;++j){
				
				
				a[temp].id=j;
				a[temp].x=i;
				cin>>a[temp].s;
				temp++;
			}
		}
		
		
		sort(a+1,a+3*n+1,cmp);
		int g[4]={};
		int ans=0;
		
		
		for(int i=1;i<=3*n;++i){
			
			if(g[a[i].id] < l && flay[a[i].x]==0){
				g[a[i].id]++;
				ans += a[i].s;
				cout<<a[i].id<<":"<<a[i].s<<endl;
				flay[a[i].x]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

