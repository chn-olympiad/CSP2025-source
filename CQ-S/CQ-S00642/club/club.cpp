#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int a,b,c;
}d[100005];
bool cmp(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	if(x.a==y.a)return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].b!=0)flag=0;
			if(d[i].c!=0)flag=0,flag2=0;
		}
		if(flag){
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=d[i].a;
			cout<<ans;
		}
		else if(flag2){
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=d[i].a;
				else ans+=d[i].b;
			}
			cout<<ans;
		}
	}
	return 0;
}
//祝SBCCF出题人全家死光 
