#include<bits/stdc++.h>
using namespace std;
int p[5005];
int g;
struct ll{
	int a,b,c;
};
int t,n,k;
ll s[5005];
void dfs(int x){
	if(x>n){
		int q=0,w=0,e=0;
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				q++;
			}
			else if(p[i]==2){
				w++;
			}
			else{
				e++;
			}
		}
		if(q<=g&&w<=g&&e<=g){
			int v=0;
			for(int i=1;i<=n;i++){
				if(p[i]==1){
					v+=s[i].a;
				}
				else if(p[i]==2){
					v+=s[i].b;
				}
				else{
					v+=s[i].c;
				}
			}
			if(k<v){
				k=v;
			}
		}
		
		return;
	}
	for(int i=1;i<=3;i++){
		p[x]=i;
		dfs(x+1);	
	}
}
int main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		k=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		g=n/2;
		dfs(1);
		cout<<k<<endl;
	}
	return 0;
} 
