#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int id,num;
}a[100005][3];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0].num>>a[i][1].num>>a[i][2].num;
			a[i][0].id=0,a[i][1].id=1,a[i][2].id=2;
			sort(a[i],a[i]+3,cmp);
		}
		priority_queue<int,vector<int>,greater<int>>qu[3];
		int ans=0;
		for(int i=0;i<n;i++){
			if(qu[a[i][0].id].size()<n/2)ans+=a[i][0].num,qu[a[i][0].id].push(a[i][0].num-a[i][1].num);
			else{
				int t=qu[a[i][0].id].top();
				if(a[i][0].num-t>a[i][1].num){
					ans+=(a[i][0].num-t);
					qu[a[i][0].id].pop(),qu[a[i][0].id].push(a[i][0].num-a[i][1].num);
				}
				else ans+=a[i][1].num;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

