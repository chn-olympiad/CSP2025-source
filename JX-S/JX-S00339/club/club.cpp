#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	bool flag=0;
}a[1000000];
bool cmp(node sa,node sb){
	return sa.a>sb.a;
}
bool cnp(node sa,node sb){
	return sa.b>sb.b;
}
bool cap(node sa,node sb){
	return sa.c>sb.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			if(a[i].a<a[i].b||a[i].a<a[i].c) continue;
			else ans+=a[i].a,a[i].flag=1;
		}
		sort(a+1,a+1+n,cnp);
		for(int i=1;i<=n/2;i++){
			if(a[i].b<a[i].a||a[i].b<a[i].c||a[i].flag==1) continue;
			else ans+=a[i].b,a[i].flag=1;
		}
		sort(a+1,a+1+n,cap);
		for(int i=1;i<=n/2;i++){
			if(a[i].c<a[i].a||a[i].c<a[i].b||a[i].flag==1) continue;
			else ans+=a[i].c,a[i].flag=1;
		}
		cout<<ans;
	}
	return 0;
}
