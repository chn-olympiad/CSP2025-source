#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;//ss:a=ab;b=bc;c=ac
}s[100001],ss[100001];
bool cmp(int x,int y){
	return x>y;
}
short vis[100001];
int al[100001];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);

		}
			int ans=0;
			int an=0,bn=0,cn=0,mx;
			for(int i=0;i<n;i++){
				ss[i].a=s[i].b-s[i].a;
				ss[i].b=s[i].c-s[i].b;
				ss[i].c=s[i].a-s[i].c;
				mx=max(max(s[i].a,s[i].b),s[i].c);
				if(s[i].a==mx){
					an++;vis[i]=1;
				}else if(s[i].b==mx){
					bn++;vis[i]=2;
				}else if(s[i].c==mx){
					cn++;vis[i]=3;
				}
				ans+=mx;
			}
			if(an>n/2){
				int ct=0;
				for(int i=0;i<n;i++){
					if(vis[i]==1){
						al[ct]=max(ss[i].a,-ss[i].c);
						ct++;
					}
				}
				sort(al,al+ct,cmp);
				for(int i=0;i<an-n/2;i++){
					ans+=al[i];
				}
			}
			if(bn>n/2){
				int ct=0;
				for(int i=0;i<n;i++){
					if(vis[i]==2){
						al[ct]=max(-ss[i].a,ss[i].b);
						ct++;
					}
				}
				sort(al,al+ct,cmp);
				for(int i=0;i<bn-n/2;i++){
					ans+=al[i];
				}
			}
			if(cn>n/2){
				int ct=0;
				for(int i=0;i<n;i++){
					if(vis[i]==3){
						al[ct]=max(-ss[i].b,ss[i].c);
						ct++;
					}
				}
				sort(al,al+ct,cmp);
				for(int i=0;i<cn-n/2;i++){
					ans+=al[i];
				}
			}
			cout<<ans<<"\n";
	}
	return 0;
}
