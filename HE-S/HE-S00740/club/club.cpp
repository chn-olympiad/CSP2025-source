#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id;
	int a1;
	int b2;
	int c3;
}a[100010];
int t;
int minn=20010;
int ans=0;
int e;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b2>>a[i].c3;
			a[i].id=i;
			ans+=max(a[i].a1,max(a[i].b2,a[i].c3));      
		}
		e=n/2;
		while(ans>e){
			for(int i=1;i<=n;i++){
				minn=min(minn,a[i].a1);
			}
			ans-=minn;
		}
		cout<<ans;
	}
	
	
	return 0;
} 
