#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N][4],ch[N],tp[4];
priority_queue<pair<int,int> >q[4];

inline int maxid(int x){
	int id=1;
	if(a[x][2]>a[x][id]) id=2;
	if(a[x][3]>a[x][id]) id=3;
	return id;
}
inline int minid(int x){
	int id=1;
	if(a[x][2]<=a[x][id]) id=2;
	if(a[x][3]<=a[x][id]) id=3;
	return id;
}
inline int midid(int x){
	return 6-maxid(x)-minid(x);
}
inline int mxid(int x){
	if(maxid(x)!=ch[x]) return x;
	return midid(x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++){
			while(!q[i].empty()) q[i].pop();
		}
		cin>>n;
		tp[1]=tp[2]=tp[3]=0;
		for(int i=1;i<=n;i++){
			ch[i]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q[0].push({max(max(a[i][1],a[i][2]),a[i][3]),i});
		}
		int ans=0;
		while(!q[0].empty()){
			int x=q[0].top().second;
			q[0].pop();
			int i=maxid(x),k=midid(x);
			if(tp[i]==n/2){
				int y=q[i].top().second;
				int j=mxid(y);
				if(a[y][j]+a[x][i]>a[x][k]+a[y][i]){
					ans-=a[y][i],tp[i]--,ch[y]=0,q[i].pop();
					ans+=a[y][j],tp[j]++,ch[y]=j,q[j].push({a[y][i]-a[y][j],y});
					ans+=a[x][i],tp[i]++,ch[x]=i,q[i].push({a[x][k]-a[x][i],x});
				}else{
					ans+=a[x][k],tp[k]++,ch[x]=k,q[k].push({a[x][i]-a[x][k],x});
				}
			}else{
				ans+=a[x][i],tp[i]++,ch[x]=i,q[i].push({a[x][k]-a[x][i],x});
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
