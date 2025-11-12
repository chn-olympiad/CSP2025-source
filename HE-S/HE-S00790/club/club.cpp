#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int T,n,num[5];
long long ans;
struct stu{
	int a1,a2,a3,no,best_num,best,diffe_num,diffe;
}g[maxn];
void neww(int i){
	int maxm;
	maxm=max(g[i].a1,max(g[i].a2,g[i].a3));g[i].best_num=maxm;
	if(maxm==g[i].a1) g[i].best=1;
	else if(maxm==g[i].a2) g[i].best=2;
	else g[i].best=3;
	if(g[i].best==1) g[i].diffe_num=max(g[i].a2,g[i].a3);
	else if(g[i].best==2) g[i].diffe_num=max(g[i].a1,g[i].a3);
	else g[i].diffe_num=max(g[i].a2,g[i].a1);
	if(g[i].diffe_num==g[i].a1) g[i].diffe=1;
	else if(g[i].diffe_num==g[i].a2) g[i].diffe=2;
	else g[i].diffe=3;
	if(g[i].best==1) g[i].diffe_num=min(g[i].best_num-g[i].a2,g[i].best_num-g[i].a3);
	else if(g[i].best==2) g[i].diffe_num=min(g[i].best_num-g[i].a1,g[i].best_num-g[i].a3);
	else g[i].diffe_num=min(g[i].best_num-g[i].a2,g[i].best_num-g[i].a1);
	return;
}
bool cmp(stu a,stu b){
	if(a.diffe_num==b.diffe_num) return a.no<b.no;
	return a.diffe_num>b.diffe_num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		num[1]=0;num[2]=0;num[3]=0;
		for(int i=1;i<=n;i++){
			g[i].no=i;
			scanf("%d%d%d",&g[i].a1,&g[i].a2,&g[i].a3);
			neww(i);
		}
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++){
			int aa=g[i].best;
//			cout<<g[i].no<<" "<<g[i].best<<" "<<g[i].diffe<<" "<<g[i].diffe_num<<endl;
			if(num[aa]<n/2){
				ans+=g[i].best_num;
				num[aa]++;
			}
			else{
				ans+=g[i].best_num-g[i].diffe_num;
				num[g[i].diffe]++;
			}
		}
		printf("%lld\n",ans);
//	cout<<"##############";
	}
	return 0;
}
