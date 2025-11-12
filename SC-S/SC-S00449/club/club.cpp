#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int t,n;
struct memb{
	int num;
	int like;
};
memb a[maxn][6];
int club[5];
int c[maxn];

int check(){
	int tmp=0;
	for (int i=1;i<=3;i++){
		if (club[i]>(n/2)){
			return i;
		}
	}
	return 0;	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++){
		priority_queue <int> q[5];
		long long ans=0;
		memset(club,0,sizeof(club));
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				a[i][j].num=j;
			}
	        cin>>a[i][1].like;
			cin>>a[i][2].like;
			if (a[i][2].like>a[i][1].like){
				swap(a[i][2],a[i][1]);
			}  
			cin>>a[i][3].like;
			if (a[i][3].like>a[i][2].like){
				swap(a[i][3],a[i][2]);
			}
			if (a[i][2].like>a[i][1].like){
				swap(a[i][2],a[i][1]);
			}
			c[i]=a[i][2].like-a[i][1].like; //小于0，便于优先队列； 
		}
		for (int i=1;i<=n;i++){
			int tmp=a[i][1].num;
			club[tmp]++;
			ans+=a[i][1].like;
			q[tmp].push(c[i]);
		}
		if (check()!=0){
			int tmp=check();
			int m=club[tmp]-(n/2);
			for (int i=1;i<=m;i++){
				ans+=q[tmp].top();
				q[tmp].pop();
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
