#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=100005;
struct node{int a,b,c;}a[N];
int T,n,m,z;
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		priority_queue<PII,vector<PII>,greater<PII> >f1,f2,f3;
		scanf("%d",&n);m=n>>1,z=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			int t=max(max(a[i].a,a[i].b),a[i].c);z+=t;
			if(t==a[i].a)f1.push(make_pair(a[i].a-a[i].b,i));
			if(t==a[i].b)f2.push(make_pair(a[i].b-a[i].c,i));
			if(t==a[i].c)f3.push(make_pair(a[i].c-a[i].a,i));
		}
		while(int(f3.size())>m){
			int i=f3.top().second;f3.pop();
			z-=a[i].c-a[i].a;
			f1.push(make_pair(a[i].a-a[i].b,i));
		}
		while(int(f1.size())>m/*||f1.top().first<0*/){
			int i=f1.top().second;f1.pop();
			z-=a[i].a-a[i].b;
			f2.push(make_pair(a[i].b-a[i].c,i));
		}
		while(int(f2.size())>m/*||f2.top().first<0*/){
			int i=f2.top().second;f2.pop();
			z-=a[i].b-a[i].c;
			f3.push(make_pair(a[i].c-a[i].a,i));
		}
		/*vector<int>f;
		while(!f3.empty()){
			int i=f3.top().second;
			f.push_back(min(a[i].c-a[i].b,a[i].c-a[i].a)),f3.pop();
		}
		sort(f.begin(),f.end());
		for(int i=0,n=f.size()-m;i<n;i++)z-=f[i];*/
		printf("%d\n",z);
	}
	return 0;
}
