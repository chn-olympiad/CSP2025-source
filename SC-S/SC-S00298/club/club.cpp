#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node{
	int k,nex,de;
	int x[4];
};
node a[10011];
int sum[4];
int n,t,ori;
int che(){
	int y[4];
	y[1]=0,y[2]=0,y[3]=0;
	for(int i=1;i<=n;i++)
		y[a[i].k]++;
	if(y[1]>y[2]&&y[1]>y[3]) ori=1;
	else if(y[2]>y[1]&&y[2]>y[3]) ori=2;
	else ori=3;
	return max(y[1],max(y[2],y[3]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			if(a[i].x[1]>a[i].x[2]&&a[i].x[1]>a[i].x[3]) a[i].k=1;
			else if(a[i].x[2]>a[i].x[1]&&a[i].x[2]>a[i].x[3]) a[i].k=2;
			else a[i].k=3;
			ans+=a[i].x[a[i].k];
//			cout<<a[i].k<<" ";
		}
//		cout<<endl;
		int l=che();
		if(l<=n/2) {
			cout<<ans<<endl;
			continue;
		}
		priority_queue<int ,vector<int>,greater<int> > d;
		for(int i=1;i<=n;i++){
			if(a[i].k==ori) d.push(min(a[i].x[a[i].k]-a[i].x[(a[i].k+2)%3],a[i].x[a[i].k]-a[i].x[(a[i].k+1)%3]));
		}
		int cnt=0;
//		cout<<ans<<endl;
		while(!d.empty()&&cnt<l-(n/2)){
			int o=d.top();
//			cout<<o<<" ";
//			cout<<ans<<" ";
			ans-=o;
			d.pop();
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}