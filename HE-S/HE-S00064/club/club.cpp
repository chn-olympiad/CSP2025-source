#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>vec[4];
struct number{
	int val,id;
}a[N][4];
int T,n;
int tmp[N];
bool cmp(number x,number y){
	return x.val>=y.val;
}
int solve(int now){
	for(int i=0;i<vec[now].size();++i)
		tmp[i]=a[vec[now][i]][1].val-a[vec[now][i]][2].val;
	sort(tmp,tmp+vec[now].size()-1);
	int res=0;
	for(int i=0;i<vec[now].size()-ceil(n/2.0);++i)
		res-=tmp[i];
	return res;
}
void init(){
	while(vec[1].size())vec[1].pop_back();
	while(vec[2].size())vec[2].pop_back();
	while(vec[3].size())vec[3].pop_back();	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j].val);
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
			vec[a[i][1].id].push_back(i);
		}
		int x=vec[1].size(),y=vec[2].size(),z=vec[3].size(),ans=0;
		for(int i=0;i<x;++i)ans+=a[vec[1][i]][1].val;
		for(int i=0;i<y;++i)ans+=a[vec[2][i]][1].val;
		for(int i=0;i<z;++i)ans+=a[vec[3][i]][1].val;
		if(x>n/2)ans+=solve(1);
		else if(y>n/2)ans+=solve(2);
		else if(z>n/2)ans+=solve(3);
		printf("%d\n",ans);
	}
	return 0;
}
