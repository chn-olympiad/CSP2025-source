#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
bool cmp(node a,node b){
	if(a.a-max(a.b,a.c)!=b.a-max(b.b,b.c))
		return a.a-a.b>b.a-b.b;
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++){
			ans+=a[i].a;
		}
		for(int i=n/2;i<n;i++){
			ans+=a[i].b;
		}
		cout<<ans; 
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
