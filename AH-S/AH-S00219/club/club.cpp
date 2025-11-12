#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q,n;
struct Node{
	int a,b,c,vis;
}t[N];
bool cmp(Node x,Node y){
	return x.a>y.a;
}
bool cmpp(Node x,Node y){
	return x.b>y.b;
}
bool cmppp(Node x,Node y){
	return x.c>y.c;
}
bool pd1=true,pd2=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++)
			t[i].a=t[i].b=t[i].c=t[i].vis=0;
		pd1=true;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			if(t[i].b!=0||t[i].c!=0)
				pd1=false;
			if(t[i].c!=0&&t[i].b!=0)
				pd2=false;
		}
		if(n==2){
			int maxx=0;
			if(t[1].a+t[2].b>maxx)
				maxx=t[1].a+t[2].b;
			if(t[1].a+t[2].c>maxx)
				maxx=t[1].a+t[2].c;
			if(t[1].b+t[2].a>maxx)
				maxx=t[1].b+t[2].a;
			if(t[1].b+t[2].c>maxx)
				maxx=t[1].b+t[2].c;
			if(t[1].c+t[2].a>maxx)
				maxx=t[1].c+t[2].a;
			if(t[1].c+t[2].b>maxx)
				maxx=t[1].c+t[2].b;
			cout<<maxx<<"\n";
		}
		else{
			if(pd1){
				int ans=0;
				sort(t+1,t+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=t[i].a,t[i].vis=1;
				cout<<ans<<"\n";
			}
			else{
				int k=n/3,p=n,ans=0,temp=0;
				sort(t+1,t+p+1,cmp);
				for(int i=1;i<=k;i++)
					ans+=t[i].a;
				sort(t+1,t+p+1,cmpp);
				for(int i=1;i<=n;i++){
					if(!t[i].vis)
						ans+=t[i].b,t[i].vis=1,temp++;
					if(temp==k)
						break;
				}
				temp=0;
				sort(t+1,t+p+1,cmppp);
				for(int i=1;i<=n;i++){
					if(!t[i].vis)
						ans+=t[i].c,t[i].vis=1,temp++;
					if(temp==k)
						break;
				}		
				p-=k*3;
				sort(t+1,t+n+1,cmp);
				for(int i=1;i<=n;i++)
					if(!t[i].vis){
						ans+=t[i].a;
						break;
					}
				if(p==2)
					for(int i=1;i<=n;i++)
						if(!t[i].vis){
							ans+=t[i].a;
							break;
						}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
} 
