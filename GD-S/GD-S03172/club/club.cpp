#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,ans;
struct Node{
	int a,b,c;
}stu[N];
priority_queue<pair<int,int>> p[5];
void dfs(int t,int s,int sum){
	if(t==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		int x,y;
		if(s==1) x=stu[i].a;
		else if(s==2) x=stu[i].b;
		else if(s==3) x=stu[i].c;
		if(i==1) y=stu[i].a;
		else if(i==2) y=stu[i].b;
		else if(i==3) y=stu[i].c;
		if(i!=s){
			dfs(t+1,s,sum+x-y);
		}
	}
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		int sum=0;
		int cnt[5]={};
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			int t=max(stu[i].a,max(stu[i].b,stu[i].c));
			sum+=t;
			int j;
			if(t==stu[i].a) j=1;
			else if(t==stu[i].b) j=2;
			else if(t==stu[i].c) j=3;
			cnt[j]++;
			if(j!=1) p[1].push({stu[i].a-t,i});
			if(j!=2) p[2].push({stu[i].b-t,i});
			if(j!=3) p[3].push({stu[i].c-t,i});
		}
//		cout<<"*"<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
		bool flag[N]={};
		int abc=0,cba;
		if(cnt[1]>n/2) abc++,cba=1;
		if(cnt[2]>n/2) abc++,cba=2;
		if(cnt[3]>n/2) abc++,cba=3;
		if(abc==1){
//			dfs(0,cba,sum);
//			cout<<ans<<endl;
		}
		while(cnt[1]>n/2){
			int x=INT_MAX,y=INT_MAX;
			while(flag[p[2].top().second]) p[2].pop();
			while(flag[p[3].top().second]) p[3].pop();
			if(cnt[2]<n/2) x=p[2].top().first;
			if(cnt[3]<n/2) y=p[3].top().first;
			if(x>y){
				sum+=x;
				flag[p[2].top().second]=1;
				p[2].pop();
				cnt[2]++,cnt[1]--;
			}else{
				sum+=y;
				flag[p[3].top().second]=1;
				p[3].pop();
				cnt[3]++,cnt[1]--;
			}
		}
		while(cnt[2]>n/2){
			int x=INT_MAX,y=INT_MAX;
			while(flag[p[1].top().second]) p[1].pop();
			while(flag[p[3].top().second]) p[3].pop();
			if(cnt[1]<n/2) x=p[1].top().first;
			if(cnt[3]<n/2) y=p[3].top().first;
			if(x>y){
				sum+=x;
				flag[p[1].top().second]=1;
				p[1].pop();
				cnt[1]++,cnt[2]--;
			}else{
				sum+=y;
				flag[p[3].top().second]=1;
				p[3].pop();
				cnt[3]++,cnt[2]--;
			}
		}
		while(cnt[3]>n/2){
			int x=INT_MAX,y=INT_MAX;
			while(flag[p[2].top().second]) p[2].pop();
			while(flag[p[1].top().second]) p[3].pop();
			if(cnt[2]<n/2) x=p[2].top().first;
			if(cnt[1]<n/2) y=p[1].top().first;
			if(x>y){
				sum+=x;
				flag[p[2].top().second]=1;
				p[2].pop();
				cnt[2]++,cnt[3]--;
			}else{
				sum+=y;
				flag[p[1].top().second]=1;
				p[1].pop();
				cnt[1]++,cnt[3]--;
			}
		}
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
//3
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
