#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct NNN{
	int id,v;
};
struct Node{
	NNN c[4];
	int cj;
}a[N];
int m,n;
int ans;
vector<Node>cl[4];
bool cmp1(NNN x,NNN y){
	if(x.v==y.v)return x.id<y.id;
	return x.v>y.v;
}
bool cmp2(Node x,Node y){
	if(x.c[1].v==y.c[1].v){
		if(x.c[2].v==y.c[2].v){
			return x.c[3].v<y.c[3].v;
		}return x.c[2].v<y.c[2].v;
	}return x.c[1].v>y.c[1].v;
}
bool cmp3(Node x,Node y){
	return x.cj>y.cj;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&m);
	while(m--){
		memset(cl,0,sizeof(cl));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].c[j].v);
				a[i].c[j].id=j;
			}sort(a[i].c+1,a[i].c+4,cmp1);
			a[i].cj=a[i].c[1].v-a[i].c[2].v;
			ans+=a[i].c[1].v;
			cl[a[i].c[1].id].push_back(a[i]);
		}/*for(int i=1;i<=3;i++){
			cout<<i<<":"<<endl;
			for(int j=0;j<cl[i].size();j++){
				for(int k=1;k<=3;k++){
					cout<<cl[i][j].c[k].id<<":"<<cl[i][j].c[k].v<<' ';
				}cout<<endl;
			}
		}cout<<ans<<endl;*/
		//for(int i=1;i<=3;i++)sort(cl[i].begin(),cl[i].end(),cmp2);
		for(int i=1;i<=3;i++){
			if(cl[i].size()*2>n){
				sort(cl[i].begin(),cl[i].end(),cmp3);
				for(int j=n/2;j<cl[i].size();j++){
					ans-=cl[i][j].cj;
				
				}break;
			}
		}printf("%d\n",ans);
	}
	return 0;
}

