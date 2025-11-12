#include<bits/stdc++.h>
using namespace std;
int a[10000];
struct member{
	int a,b,c;
}d[10000];
bool cmp(member x,member y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=d[i].a;
		}
		for(inti=n/2;i<=n;i++){
			ans+=max(d[i].b+d[i].c)
		}
		cout<<ans;
		
	}
}
