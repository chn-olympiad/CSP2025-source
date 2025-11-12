#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e5+5;
int T,n;
int a[N][3];
struct Stu{
	int id,k;
};
bool operator<(Stu x, Stu y){
	if(x.k==0)
		return max(a[x.id][1],a[x.id][2])-a[x.id][0]<max(a[y.id][1],a[y.id][2])-a[y.id][0];
	if(x.k==1)
		return max(a[x.id][0],a[x.id][2])-a[x.id][1]<max(a[y.id][0],a[y.id][2])-a[y.id][1];
	if(x.k==2)
		return max(a[x.id][1],a[x.id][0])-a[x.id][2]<max(a[y.id][1],a[y.id][0])-a[y.id][2];
}
priority_queue<Stu>q[3];
ll sum;
int choos(int id,int no){
	if(no==4){
		if(a[id][0]>=a[id][1]&&a[id][0]>=a[id][2])return 0;
		if(a[id][1]>=a[id][0]&&a[id][1]>=a[id][2])return 1;
		if(a[id][2]>=a[id][1]&&a[id][2]>=a[id][0])return 2;
	}
	if(no==0){
		if(a[id][1]>a[id][2])return 1;
		else return 2;
	}
	if(no==1){
		if(a[id][0]>a[id][2])return 0;
		else return 2;
	}
	if(no==2){
		if(a[id][1]>a[id][0])return 1;
		else return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int s1=choos(i,4),s2;
			q[s1].push({i,s1});
			sum+=a[i][s1];
			if(q[s1].size()>n/2){
				Stu t=q[s1].top();
				q[s1].pop();
				sum-=a[t.id][t.k];
				s2=choos(t.id,s1);
				q[s2].push({t.id,s2});
				sum+=a[t.id][s2];
			}
			//cout<<sum<<endl;
		}printf("%lld\n",sum);
	}
	return 0;
} 
