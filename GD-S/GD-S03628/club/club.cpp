#include<bits/stdc++.h>
using namespace std;
struct node{
	int m,c;
	bool operator < (const node o) const {
		return m<o.m;
	}
}a[111111][4];
bool cmp(node x,node y){
	return x.m>y.m;
}
int t,cnt[4];
priority_queue<node> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		while(!q.empty()) q.pop();
		memset(cnt,0,sizeof(cnt));
		long long n,ans=0,len,pos;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].m;
				a[i][j].c=j;
			}
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4,cmp);
			ans+=a[i][1].m;
			cnt[a[i][1].c]++;
			q.push(node{a[i][2].m-a[i][1].m,a[i][1].c});
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]-n/2>0){
				len=cnt[i]-n/2;
				pos=i;
			}
		}
		while(len>0){
			if(q.top().c==pos){
				ans+=q.top().m;
				len--;
			}
			q.pop(); 
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
