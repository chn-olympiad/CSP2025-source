//GZ-S00187 盘州市第二中学 徐世鹏 
#include<bits/stdc++.h>
#define Max(x,y,z) max(max(x,y),z)
#define Min(x,y,z) min(min(x,y),z)

using namespace std;

const int N=1e5+10;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int,int>PII;

struct Node{
	int a[3];
	int rt[3];
	int pos;
}stu[N];

int n;
int cnt[3];
LL sum;

bool cc(PII x,PII y){
	return x.first>y.first;
}


int Cut(Node x){
	return x.a[x.rt[0]]-x.a[x.rt[1]];
}

bool cmp(Node x,Node y){
	//return Max(x.a,x.b,x.c)>Max(y.a,y.b,y.c);
	//if(Cut(x)==Cut(y)){
		for(int i=0;i<3;i++)
		if(x.a[x.rt[i]]!=y.a[y.rt[i]])
		return x.a[x.rt[i]]>y.a[y.rt[i]];
	//}
	//return Cut(x)>Cut(y);
	return 1;
}

void St(int x){
	PII a[3];
	for(int i=0;i<3;i++)
		a[i]={stu[x].a[i],i};
	sort(a,a+3,cc);
	for(int i=0;i<3;i++)
		stu[x].rt[i]=a[i].second;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		sum=0;
		priority_queue<PII>q[3];
		for(int i=0;i<3;i++){
			cnt[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a[0],&stu[i].a[1],&stu[i].a[2]);
			St(i);
		}
		sort(stu+1,stu+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=i;
			int qa=stu[x].rt[0];
			sum+=stu[x].a[qa];
			q[qa].push({-Cut(stu[x]),x});
			if(q[qa].size()>n/2){
			int t=q[qa].top().second;
			Node item=stu[t];
			q[qa].pop();
			int qb=item.rt[1];
			sum-=Cut(item);
			q[qb].push({-INF,t});
		}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
