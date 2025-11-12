#include <bits/stdc++.h>
using namespace std;
struct x{
int a;
int b;
int c;
};
int fa=0,fb=0,fc=0;
x e[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,ans;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int x,ans=0;
		cin>>x;
		
		for(int i1=1;i1<=x;i1++){
			cin>>e[i1].a>>e[i1].b>>e[i1].c;
			
				ans+=max(e[i1].a,max(e[i1].b,e[i1].c));
			
		}
    
    
	cout<<ans<<endl;
	}
	return 0;
} //3 4 4 2 1 3 2 4 5 3 4 3 5 1
