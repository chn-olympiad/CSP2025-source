#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,id;
}a[100005][5];
struct pueue{
	node a[100005]={};
	int tot=0;
	void repair_up(int x){
		if(x>(tot>>1)) return;
		int up=x>>1;
		if(a[x].x>a[up].x){
			swap(a[x].x,a[up].x);
			repair_up(up);
		}
	}
	void repair_down(int x){
		if(x>(tot>>1)) return;
		int l=x<<1,r=l+1,num=a[l].x>a[r].x? l:r;
		if(a[x].x>a[num].x){
			swap(a[x].x,a[num].x);
			repair_down(num);
		}
	}
	void push(int x){
		a[++tot].x=x;
		repair_up(tot);
	}
	void pop(){
		swap(a[1].x,a[tot--].x);
		repair_down(1);
	}
	int top(){
		int tmp=a[1].x;
		pop();
		return tmp;
	}
}p[4][4];
int t,n,cnt[10];
long long ans;
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));ans=0;cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].x,&a[i][2].x,&a[i][3].x);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			if(cnt[a[i][1].id]==(n>>1)){
				cnt[a[i][2].id]++;
				int u=p[a[i][1].id][a[i][2].id].top(),num=a[i][2].x-a[i][1].x;p[a[i][1].id][a[i][2].id].pop();
				if(u<num){
					ans+=a[i][2].x;
				}else{
					ans+=u+a[i][1].x;
					p[a[i][1].id][a[i][2].id].push(num);
				}
			}else{
				cnt[a[i][1].id]++;
				p[a[i][1].id][a[i][2].id].push(a[i][2].x-a[i][1].x);
			}
		}
		printf("%lld\n",ans);
	}
}
