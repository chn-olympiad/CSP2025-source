//GZ-S00030 ËçÑôÏØËçÑôÖÐÑ§ ÓàÏè 
#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+86;
queue<int>q;
struct node{
	int i;
	int num;
	bool operator<(const node&a)const{
	return a.num<num;
	}
}s[maxn];
int a1[maxn];
int a2[maxn];
int a3[maxn];
bool vis[maxn][4];
int find(int i){
	int x=0;
	int num=0;
	if(a1[i]>x){
		x=a1[i];
		num=1;
	}
	if(a2[i]>x){
		x=a2[i];
		num=2;
	}
	if(a3[i]>x){
		x=a3[i];
		num=3;
	}
	return num;
}
priority_queue<node>q1;
priority_queue<node>q2;
priority_queue<node>q3;
void init(int n){
	while(!q.empty())
	q.pop();
	while(!q1.empty())
	q1.pop();
	while(!q2.empty())
	q2.pop();
	while(!q3.empty())
	q3.pop();
}
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		
	int n;
    cin>>n;
    init(n);
    ans=0;
    memset(a1,0,sizeof a1);
    memset(a2,0,sizeof a2);
    memset(a3,0,sizeof a3);
    memset(vis,0,sizeof vis);
    int m=n/2;
    for(int i=1;i<=n;i++){
    scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
	}
	
	for(int i=1;i<=n;i++)
	q.push(i);
	
	while(!q.empty()){
		int u=q.front();
		int num=find(u);
		q.pop();
		if(num==1){
			if(q1.size()>=m){
				if(vis[u][1]) continue;
				node v;
				v.i=u;
				v.num=a1[u];
				q1.push(v);
				v=q1.top();
				int i=v.i;
				q1.pop();
				q.push(i);
				vis[u][1]=1;
			}
			else {
				node v;
				v.i=u;
				v.num=a1[u];
				q1.push(v);
			}
		}
		if(num==2){
			if(q2.size()>=m){
				if(vis[u][2] ) continue;
				node v;
				v.i=u;
				v.num=a2[u];
				q2.push(v);
				v=q2.top();
				int i=v.i;
				q2.pop();
				q.push(i);
				vis[u][2]=1;
			}
			else {
				node v;
				v.i=u;
				v.num=a2[u];
				q2.push(v);
			}
		}
		if(num==3){
			if(q3.size()>=m){
				
				if(vis[u][3] ) continue;
				node v;
				v.i=u;
				v.num=a3[u];
				q3.push(v);
				v=q3.top();
				int i=v.i;
				q3.pop();
				q.push(i);
			}
			else {
				node v;
				v.i=u;
				v.num=a3[u];
				q3.push(v);
			}
		}
	}
	while(q1.size()!=0){
		node v=q1.top();
		ans+=v.num;
		q1.pop(); 
	}
	while(q3.size()!=0){
		node v=q3.top();
		ans+=v.num;
		q3.pop(); 
	}
	while(q2.size()!=0){
		node v=q2.top();
		ans+=v.num;
		q2.pop(); 
	}
	cout<<ans<<endl;	
}
    fclose(stdin);
	fclose(stdout);	
    return 0;
}

