#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[100500][4];
int max1[100500];
int l[4];
int ans;
struct node{
	int c;
	int id;
	operator<(const node &x)const {
		return x.c<c;
	};
};
priority_queue<node> q[4];
void work(){
	memset(l,0,sizeof(l));
	memset(max1,0,sizeof(max1));
	for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
			max1[i]=1;
		}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
			max1[i]=2;
		}else{
			max1[i]=3;
		}
		int j=max1[i];
		if(j==1){
			int max2=max(a[i][2],a[i][3]);
			q[1].push((node){a[i][1]-max2,i});
		}else if(j==2){
			int max2=max(a[i][1],a[i][3]);
			q[2].push((node){a[i][2]-max2,i});
		}else{
			int max2=max(a[i][1],a[i][2]);
			q[3].push((node){a[i][3]-max2,i});
		}
		if(l[j]<n/2){
			l[j]++;
			ans+=a[i][j];
//			ans=a[i][j];
		}else{
			node v=q[j].top();
			q[j].pop();
			ans+=a[i][j]-v.c;
//			ans=a[i][j]-v.c;
//			cout<<v.c<<">"<<endl;
		}
//		cout<<i<<" "<<j<<" :"<<ans<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}

