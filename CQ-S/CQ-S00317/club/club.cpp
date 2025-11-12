#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n;
struct node{
	int x,y;
};
vector<node> t[3];
bool cmp(node x,node y){
	return x.x-x.y<y.x-y.y;
}
int read(){
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<3;i++)t[i].clear();
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			ans+=max(max(a,b),c);
			if(a>=b&&a>=c)t[0].push_back({a,max(b,c)});
			else if(b>=c)t[1].push_back({b,max(a,c)});
			else t[2].push_back({c,max(a,b)});
		}
		if(t[1].size()>n/2)swap(t[0],t[1]);
		if(t[2].size()>n/2)swap(t[0],t[2]);
		if(t[0].size()>n/2){
			sort(t[0].begin(),t[0].end(),cmp);
			for(int i=0;i<t[0].size()-n/2;i++){
				ans-=t[0][i].x-t[0][i].y;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}