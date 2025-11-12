#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct node{
	int a,b,c;
}a[100010];
vector<int> b[3];
bool cmp0(int x,int y){
	return a[x].a-a[x].b<a[y].a-a[y].b;
}
bool cmp1(int x,int y){
	return a[x].b-a[y].c<a[y].b-a[y].c;
}
bool cmp2(int x,int y){
	return a[x].c-a[y].a<a[y].c-a[y].a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		b[0].clear();
		b[1].clear();
		b[2].clear();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				b[0].push_back(i);
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				b[1].push_back(i);
			}else{
				b[2].push_back(i);
			}
		}
		sort(b[0].begin(),b[0].end(),cmp0);
		while(b[0].size()>n/2){
			b[1].push_back(b[0][0]);
			b[0].erase(b[0].begin());
		}
		sort(b[1].begin(),b[1].end(),cmp1);
		while(b[1].size()>n/2){
			b[2].push_back(b[1][0]);
			b[1].erase(b[1].begin());
		}
		sort(b[2].begin(),b[2].end(),cmp2);
		while(b[2].size()>n/2){
			b[0].push_back(b[2][0]);
			b[2].erase(b[2].begin());
		}
		for(int i=0;i<b[0].size();i++){
			ans+=a[b[0][i]].a;
		}
		for(int i=0;i<b[1].size();i++){
			ans+=a[b[1][i]].b;
		}
		for(int i=0;i<b[2].size();i++){
			ans+=a[b[2][i]].c;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
