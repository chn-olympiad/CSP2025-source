#include<bits/stdc++.h>
using namespace std;
int T,n,sz,ans,ct[20005];
struct stu{
	int a;
	int b;
	int c;
}a;
vector<stu>cl[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(ct,0,sizeof(ct));
		for(int i=1;i<=3;i++){
			cl[i].clear();
			cl[i].shrink_to_fit();
		}
		scanf(" %d",&n);
		for(int i=1,t;i<=n;i++){
			scanf(" %d %d %d",&a.a,&a.b,&a.c);
			if(a.a>=a.b&&a.a>=a.c){
				cl[1].push_back(a);
			}
			else{
				if(a.b>=a.c){
					cl[2].push_back(a);
				}
				else{
					cl[3].push_back(a);
				}
			}
		}
		n>>=1;
		
		
		sz=cl[1].size();
		if(sz>n){
			for(int i=0;i<sz;i++){
				ct[min(cl[1][sz].a-cl[1][sz].b,cl[1][sz].a-cl[1][sz].c)]++;
			}
			sz-=n;
			for(int i=0;sz&&i<=20000;i++){
				if(sz>=ct[i]){
					sz-=ct[i];
					ans-=ct[i]*i;
				}
				else{
					ans-=sz*i;
					sz=0;
				}
			}
			for(int i=0;i<n;i++){
				ans+=cl[1][sz].a;
			}
			cl[1].clear();
		}
		
		
		sz=cl[2].size();
		if(sz>n){
			for(int i=0;i<sz;i++){
				ct[min(cl[2][sz].b-cl[1][sz].a,cl[1][sz].b-cl[1][sz].c)]++;
			}
			sz-=n;
			for(int i=0;sz&&i<=20000;i++){
				if(sz>=ct[i]){
					sz-=ct[i];
					ans-=ct[i]*i;
				}
				else{
					ans-=sz*i;
					sz=0;
				}
			}
			for(int i=0;i<n;i++){
				ans+=cl[2][sz].b;
			}
			cl[2].clear();
		}
		
		
		sz=cl[3].size();
		if(sz>n){
			for(int i=0;i<sz;i++){
				ct[min(cl[3][sz].c-cl[1][sz].a,cl[1][sz].c-cl[1][sz].b)]++;
			}
			sz-=n;
			for(int i=0;sz&&i<=20000;i++){
				if(sz>=ct[i]){
					sz-=ct[i];
					ans-=ct[i]*i;
				}
				else{
					ans-=sz*i;
					sz=0;
				}
			}
			for(int i=0;i<n;i++){
				ans+=cl[3][sz].c;
			}
			cl[3].clear();
		}
		
		
		for(auto i:cl[1]){
			ans+=i.a;
		}
		for(auto i:cl[2]){
			ans+=i.b;
		}
		for(auto i:cl[3]){
			ans+=i.c;
		}
		printf("%d\n",ans);
	}
	return 0;
}
