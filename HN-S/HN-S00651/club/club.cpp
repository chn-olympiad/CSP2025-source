#include<bits/stdc++.h>
using namespace std;
const int N=100010;
priority_queue<int,vector<int>,greater<int> >q[5];
int cnt[5];
int n;
int a[N][5];
int ans;
void doit(){
	ans=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty())q[i].pop();
		cnt[i]=0;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		int mx=0,t1,t2;
		a[i][0]=-1;
		for(int j=1;j<=3;j++){
			if(a[i][j]>a[i][mx])mx=j;
		}
		t1=mx%3+1;
		t2=t1%3+1;
		cnt[mx]++;
		q[mx].push(a[i][mx]-max(a[i][t1],a[i][t2]));
		ans+=a[i][mx];
	}
	int mx=0;
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			mx=i;
		}
	}
	if(!mx){
		printf("%d\n",ans);
		return;
	}
	while(cnt[mx]>n/2){
		ans-=q[mx].top();
		cnt[mx]--;
		q[mx].pop();
	}printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)doit();
}
/*
14:39 看题，显然priority_queue
15:02 假了
15:07 过大样例 
*/
