#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
int T,n,ans;
int a[100005][10];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		int x,flag,now,y;
		for(int i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a[i][4]=1;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				a[i][4]=2;
			}
			else{
				a[i][4]=3;
			}//
			if(a[i][4]==1){
				if(a[i][2]>=a[i][3]) a[i][5]=2,a[i][6]=3;
				else a[i][5]=3,a[i][6]=2;
			}
			else if(a[i][4]==2){
				if(a[i][1]>=a[i][3]) a[i][5]=1,a[i][6]=3;
				else a[i][5]=3,a[i][6]=1;
			}
			else{
				if(a[i][1]>=a[i][2]) a[i][5]=1,a[i][6]=2;
				else a[i][5]=2,a[i][6]=1;
			}
//			cout<<"__"<<a[i][4]<<' '<<a[i][5]<<' '<<a[i][6]<<'\n';
		}
		priority_queue<P,vector<P>,greater<P> >q[4];
		for(int i=1;i<=n;i++){
			flag=1;now=3;
			while(flag){
				now++;
				y=a[i][now];
				if(q[y].size()>=n/2){
					x=q[y].top().second;
					if((a[i][y]+a[x][a[x][a[x][0]+1]])>=(a[x][y]+a[i][a[i][now+1]])){
						q[a[x][a[x][0]+1]].push(make_pair(a[x][a[x][a[x][0]+1]]-a[x][a[x][a[x][0]+1]],x));
						a[x][0]++;
						q[y].pop();
						q[y].push(make_pair(a[i][y]-a[i][a[i][now+1]],i));
						a[i][0]=now;
						flag=0;
					}
				}
				else{
					q[y].push(make_pair(a[i][y]-a[i][a[i][now+1]],i));
					a[i][0]=now;
					flag=0;
				}
			}
		}
		ans=0;
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				x=q[i].top().second; 
				ans+=a[x][a[x][a[x][0]]];
//				cout<<i<<' '<<q[i].top().second<<'\n';
				q[i].pop();
			}
		}		
		cout<<ans<<'\n';
	}
	return 0;
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
out:18 4 13
*/
}

