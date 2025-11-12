#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
void read(int& x){
	x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
}
const int N=1e5+5;
int t,n,a[N][5],sum[5];
priority_queue<int,vector<int>,greater<int> > q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		int ans=0;
		read(n);
		for(int i=1;i<=n;i++){
			int id=0,se=0;
			for(int j=1;j<=3;j++){
				read(a[i][j]);
				if(id==0||a[i][id]<=a[i][j]){
					se=id;
					id=j;
				}
				else if(se==0||a[i][se]<=a[i][j]){
					se=j;
				}
			}
			q[id].push(a[i][id]-a[i][se]);
			sum[id]++;
			ans+=a[i][id];
		}
		for(int j=1;j<=3;j++){
			if(sum[j]>n/2){
				while(sum[j]>n/2){
					sum[j]--;
					ans-=q[j].top();
					q[j].pop();
				}
				break;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=3;i++){
			sum[i]=0;
			while(!q[i].empty()){
				q[i].pop();
			}
		}
	}
	return 0;
}
