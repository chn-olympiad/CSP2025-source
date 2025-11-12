#include<bits/stdc++.h>
using namespace std;
long long n;
long long num[100005][5];
long long mxp[100005];
long long np;
long long ans;
long long cnt[5];
struct node{
	long long num,u,v;
};
priority_queue<node> q;
bool operator<(const node &x,const node &y){
	return x.num>y.num;
}
long long T;
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>T;
for(int wasd=1;wasd<=T;wasd++){
	memset(num,0,sizeof(num));
	memset(mxp,0,sizeof(mxp));
	np=0;
	ans=0;
	memset(cnt,0,sizeof(cnt));
	while(!q.empty())q.pop();
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>num[i][j];
			if(mxp[i]==0||num[i][j]>num[i][mxp[i]]){
				mxp[i]=j;
			}
		}
					//	cout<<"chose "<<i<<" "<<mxp[i]<<" "<<num[i][mxp[i]]<<endl;
		ans+=num[i][mxp[i]];
		cnt[mxp[i]]++;
	}
	//cout<<"cnt"<<endl;
	//for(int i=1;i<=3;i++)cout<<i<<" "<<cnt[i]<<endl;
//	cout<<endl;
	for(int i=1;i<=3;i++){
		if(np==0||cnt[i]>cnt[np]){
			np=i;
		}
	}
	if(cnt[np]<=n/2){
		cout<<ans<<endl;
		continue;				//!!!!!!!!!!!!!!!!!!!!!!
	}
	
	for(int i=1;i<=n;i++){
		if(mxp[i]!=np)continue;
		long long rmxp=0;
		for(int j=1;j<=3;j++){
			if(j==mxp[i])continue;
			if(rmxp==0||num[i][j]>num[i][rmxp]){
				rmxp=j;
			}
			
		}
		node tp;
		tp.num=num[i][mxp[i]]-num[i][rmxp];
		tp.u=mxp[i];
		tp.v=rmxp;
		q.push(tp);
	}

	
	
	
	while(cnt[np]>n/2){ //&&!q.empty()!!!!!!!!!!!!!!!!!!!!!
		node tp=q.top();	//	cout<<"qu "<<tp.num<<" "<<tp.u<<" "<<tp.v<<endl;
		q.pop();
		ans-=tp.num;
		cnt[np]--;
		cnt[tp.v]++;
	}
	cout<<ans<<endl;
	
	
}
	return 0;
} 
/*
3

4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0


18
4
13
*/











