#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,maxmy;
}my[100005];
int n,t,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;ans=0;
		memset(my,0,sizeof(my));
//		for(int i=0;i<100005;i++){
//			my[i].a=0;my[i].b=0;my[i].c=0;my[i].maxmy=0;
//		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>my[i].a>>my[i].b>>my[i].c;
			my[i].maxmy=max(my[i].a,max(my[i].b,my[i].c));
			ans+=my[i].maxmy;
		}
		cout<<ans;
	} 
	return 0;
}
