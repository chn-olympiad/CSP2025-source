#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,cnt[4],ans;
vector<int>v[4];
struct node{
	int num,id;
	void in(int x){
		id=x;
		scanf("%d",&num);
	}
	bool operator<(const node&o)const{
		return num>o.num;
	}
};
struct dat{
	node x[4];
	int dif,id;
	void in(int i){
		id=i;
		x[1].in(1);
		x[2].in(2);
		x[3].in(3);
		sort(x+1,x+4);
		cnt[x[1].id]++;
		v[x[1].id].push_back(id);
		ans+=x[1].num;
		dif=x[1].num-x[2].num;
	}
}a[100010];
bool cmp(const int&x,const int&y){
	return a[x].dif<a[y].dif;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t--;){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)a[i].in(i);
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			int tmp=0;
			if(cnt[1]>n/2)tmp=1;
			if(cnt[2]>n/2)tmp=2;
			if(cnt[3]>n/2)tmp=3;
			sort(v[tmp].begin(),v[tmp].end(),cmp);
			for(int i=0;i<cnt[tmp]-n/2;i++){
				ans-=a[v[tmp][i]].dif;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
