#include<bits/stdc++.h>
using namespace std;

int t,n;
struct node{
	int c,id;
}a[100005][3];

bool cmp(node a,node b){
	return a.c>b.c;
}

priority_queue<int,vector<int>,greater<int> > q[4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i][1].c>>a[i][2].c>>a[i][3].c;
			a[i][1].id=1;a[i][2].id=2;a[i][3].id=3; 
			sort(a[i]+1,a[i]+4,cmp);
//			cout<<a[i][1].c<<" "<<a[i][2].c<<" "<<a[i][3].c<<endl;
		}
		long long ans=0;
		for(int i=1;i<=3;i++)
			while(!q[i].empty())
				q[i].pop();
		for(int i=1;i<=n;i++)
			if((int)q[a[i][1].id].size()<n/2){
				ans+=1ll*a[i][1].c;
//				cout<<i<<" "<<a[i][1].c<<endl;
				q[a[i][1].id].push(a[i][1].c-a[i][2].c);
			}else if(q[a[i][1].id].top()<=a[i][1].c-a[i][2].c){
				ans+=1ll*(a[i][1].c-q[a[i][1].id].top());
				q[a[i][1].id].pop();
				q[a[i][1].id].push(a[i][1].c-a[i][2].c);
			}else{
				ans+=1ll*a[i][2].c;
//				cout<<i<<" "<<a[i][1].c<<endl;
				q[a[i][2].id].push(1e9);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
