#include<bits/stdc++.h>
using namespace std;
int cl[10];
int n;
long long ans;
struct node{
	int a,club;
}a[100005][5];
struct Node{
	int a,id;bool bok;
}b[100005];
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp1(Node a,Node b){
	return a.a<b.a;
}
bool cmp2(Node a,Node b){
	return a.id<b.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		memset(cl,0,sizeof(cl));
		bool flag=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j].a);
				a[i][j].club=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
			cl[a[i][1].club]++;
		}
		for(int i=1;i<=3;i++){
			if(cl[i]>n/2){
				for(int j=1;j<=n;j++){
					if(a[j][1].club==i){
						b[j].id=j;
						b[j].bok=0;
						b[j].a=a[j][1].a-a[j][2].a;
					}
				}
				sort(b+1,b+n+1,cmp1);
				for(int j=1;j<=cl[i]-n/2;j++){
					b[j].bok=1;
				}
				sort(b+1,b+n+1,cmp2);
				for(int j=1;j<=n;j++){
					if(b[j].bok){
						if(a[j][2].a>a[j][3].a){
							if(cl[a[j][2].club]==n/2){
								
								cl[a[j][3].club]++;
								swap(a[j][1],a[j][3]);
							}else{
								cl[a[j][2].club]++;
								swap(a[j][1],a[j][2]);
								
							}
							
						}else{
							if(cl[a[j][3].club]==n/2){
								
								cl[a[j][2].club]++;
								swap(a[j][1],a[j][2]);
							}else{
								cl[a[j][3].club]++;
								swap(a[j][1],a[j][3]);
								
							}
							
						}
						b[j].bok=0;
					}
				}
			}
		} 
		for(int i=1;i<=n;i++){
			ans+=a[i][1].a;
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
} 
