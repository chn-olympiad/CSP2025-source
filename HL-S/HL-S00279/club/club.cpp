#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int a,b,c;
}s[N];
bool cmp1(node o,node p){
	if(max(o.a,max(o.b,o.c))>=max(p.a,max(p.b,p.c)))return true;
	return false;
}
bool cmp2(node o,node p){
	if(max(o.a,max(o.b,o.c))<=max(p.a,max(p.b,p.c)))return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int k=n/2;
		int ans1=0,ans2=0,av=0,bv=0,cv=0;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s,s+n,cmp1);
		bool vis[N];
		memset(vis,false,3);
		for(int i=0;i<n;i++){
			if(!vis[0]&&s[i].a>=s[i].b&&s[i].a>=s[i].c){
				ans1+=s[i].a;
				av++;
				if(av>=k){
					vis[0]=true;
				}
			}
			else if(!vis[1]&&s[i].b>=s[i].a&&s[i].b>=s[i].c){
				ans1+=s[i].b;
				bv++;
				if(bv>=k){
					vis[1]=true;
				}
			}
			else if(!vis[2]&&s[i].c>=s[i].b&&s[i].c>=s[i].a){
				ans1+=s[i].c;
				cv++;
				if(cv>=k){
					vis[2]=true;
				}
			}else if(!vis[0]){
				ans1+=s[i].a;
				av++;
				if(av>=k){
					vis[0]=true;
				}
			}else if(!vis[1]){
				ans1+=s[i].b;
				bv++;
				if(bv>=k){
					vis[1]=true;
				}
			}else if(!vis[2]){
				ans1+=s[i].c;
				cv++;
				if(cv>=k){
					vis[2]=true;
				}
			}
		}
		
		sort(s,s+n,cmp2);
		memset(vis,false,3);

		for(int i=0;i<n;i++){
			if(!vis[0]&&s[i].a>=s[i].b&&s[i].a>=s[i].c){
				ans2+=s[i].a;
				av++;
				if(av>=k){
					vis[0]=true;
				}
			}
			else if(!vis[1]&&s[i].b>=s[i].a&&s[i].b>=s[i].c){
				ans2+=s[i].b;
				bv++;
				if(bv>=k){
					vis[1]=true;
				}
			}
			else if(!vis[2]&&s[i].c>=s[i].b&&s[i].c>=s[i].a){
				ans2+=s[i].c;
				cv++;
				if(cv>=k){
					vis[2]=true;
				}
			}else if(!vis[0]){
				ans2+=s[i].a;
				av++;
				if(av>=k){
					vis[0]=true;
				}
			}else if(!vis[1]){
				ans2+=s[i].b;
				bv++;
				if(bv>=k){
					vis[1]=true;
				}
			}else if(!vis[2]){
				ans2+=s[i].c;
				cv++;
				if(cv>=k){
					vis[2]=true;
				}
			}
		}
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}
