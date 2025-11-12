#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}s[N];
long long ans;
int a,b,c,n;
bool cmp(node a,node b){
	return a.a>b.a;
}bool cmpb(node a,node b){
	return a.b>b.b;
}bool cmpc(node a,node b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0,a=0,b=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b&&s[i].a>s[i].c){
				a++;
			}if(s[i].b>s[i].a&&s[i].b>s[i].c){
				b++;
			}if(s[i].c>s[i].b&&s[i].c>s[i].a){
				c++;
			}
		}
		if(c>n/2){
			sort(s+1,s+n+1,cmpc);
		}else if(b>n/2){
			sort(s+1,s+n+1,cmpb);
		}
		else{
			sort(s+1,s+n+1,cmp);
		}
		a=0,b=0,c=0;
		for(int i=1;i<=n;i++){
			if(s[i].a>s[i].b&&s[i].a>s[i].c){
				if(a<n/2){
	                a++;
					ans+=s[i].a;
					continue;
				}else{
					ans+=max(s[i].b,s[i].c);
					continue;
				}
			}if(s[i].b>s[i].a&&s[i].b>s[i].c){
				if(b<n/2){
					b++;
					ans+=s[i].b;
					continue;
				}else{
					ans+=max(s[i].a,s[i].c);
					continue;
				}
			}if(s[i].c>s[i].b&&s[i].c>s[i].a){
				if(c<=n/2){
					c++;
					ans+=s[i].c;
					continue;
				}else{
					ans+=max(s[i].b,s[i].a);
					continue;
				}
	 		}
			ans+=max(s[i].a,max(s[i].b,s[i].c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
