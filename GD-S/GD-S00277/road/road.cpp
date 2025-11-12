#include<bits/stdc++.h>
using namespace std;
struct h{
	int a,b,c;
}l[100005];

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].b>>l[i].c;
		ans+=l[i].c;
	}
	cout<<ans;
} 
