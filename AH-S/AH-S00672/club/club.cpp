#include<cstdio>
#include<algorithm>
using namespace std;
int cl1,cl2,cl3,n,t;
struct node{
	int x,y,z;
}s;
int max(int a,int b){
	return a>b?a:b;
}
node club1[100005],club2[100005],club3[100004];
bool cmp1(node a,node b){
	return a.x-max(a.y,a.z)>b.x-max(b.y,b.z);
}
bool cmp2(node a,node b){
	return a.y-max(a.x,a.z)>b.y-max(b.x,b.z);
}
bool cmp3(node a,node b){
	return a.z-max(a.y,a.x)>b.z-max(b.y,b.x);
}
int maxn(int a,int b,int c){
	if(max({a,b,c})==a) return 1;
	else if(max({a,b,c})==b) return 2;
	else return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0,cl1=0,cl2=0,cl3=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&s.x,&s.y,&s.z);
			if(maxn(s.x,s.y,s.z)==1) club1[++cl1]=s,ans+=s.x;
			else if(maxn(s.x,s.y,s.z)==2) club2[++cl2]=s,ans+=s.y;
			else club3[++cl3]=s,ans+=s.z;
		}
		if(cl1>(n>>1)) {
			sort(club1+1,club1+cl1+1,cmp1);
			while(cl1>(n>>1)){
				ans=ans-club1[cl1].x+max(club1[cl1].y,club1[cl1].z);
				--cl1;
			}
		}
		else if(cl2>(n>>1)){
			sort(club2+1,club2+cl2+1,cmp2);
			while(cl2>(n>>1)){
				ans=ans-club2[cl2].y+max(club2[cl2].x,club2[cl2].z);
				--cl2;
			}
		}
		else if(cl3>(n>>1)){
			sort(club3+1,club3+cl3+1,cmp3);
			while(cl3>(n>>1)){
				ans=ans-club3[cl3].z+max(club3[cl3].x,club3[cl3].y);
				--cl3;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}