#include<bits/stdc++.h>
using namespace std;
int t,n;
bool used[100010];
struct node{
	int a,b,c;
}members[100010];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool cmp3(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ans,cnt;
	cin>>t;
	while(t--){
		ans=0;
		memset(used,0,sizeof(used));
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>members[i].a>>members[i].b>>members[i].c;
		}
		sort(members+1,members+n+1,cmp1);
		for(int i=1;i<=m;i++) ans+=members[i].a;
		//cnt=0;
		//while(cnt<m){
		//	if(!used[cnt]) ans+=members[cnt+1].a;
		//	used[cnt]=true;
		//	cnt++;
		//	cout<<members[cnt].a<<" ";
		//}
		//cout<<endl;
		//sort(members+1,members+n+1,cmp2);
		//cnt=0;
		//while(cnt<m){
		//	if(!used[cnt+m]) ans+=members[cnt+1+m].b;
		//	used[cnt+m]=true;
		//	cnt++;
		//	cout<<members[cnt+m].b<<" ";
		//}
		//cout<<endl;
		//sort(members+1,members+n+1,cmp3);
		//cnt=0;
		//while(cnt<m){
		//	if(!used[cnt+m+m]) ans+=members[cnt+1+m+m].c;
		//	used[cnt+m+m]=true;
		//	cnt++;
		//	cout<<members[cnt+m+m].c<<" ";
		//}
		//cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
