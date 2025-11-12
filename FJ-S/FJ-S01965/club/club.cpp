#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e5+5; 
int T,n;
int cnt[4];
pair<int,int> a[N][4];

inline int read(){
	int x=0;
	char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		for(int i=1;i<=3;i++) cnt[i]=0;
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].first=read();
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+4);
			reverse(a[i]+1,a[i]+4);
			ans+=a[i][1].first;
			cnt[a[i][1].second]++;
		}
		int id=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) id=i;
		}
		if(!id){
			printf("%d\n",ans);
			continue;
		}
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			if(a[i][1].second==id) q.push(a[i][2].first-a[i][1].first);
		}
		for(int i=1;i<=cnt[id]-n/2;i++){
			ans+=q.top();
			q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}

