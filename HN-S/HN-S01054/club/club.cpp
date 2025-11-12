#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,id1;
	long long y,id2;
}a[100005];
long long t,cnt[5],ans,n,x,y,z,maxx1,maxx2;
bool cmp(node x,node y){
	return x.x-x.y>y.x-y.y;
}
void chu(){
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
}
void work(int i){
	a[i].x=maxx1;
	a[i].y=maxx2;
	if(maxx1==x){
		a[i].id1=1;
		if(maxx2==y)a[i].id2=2;
		else a[i].id2=3;
	}else if(maxx1==y){
		a[i].id1=2;
		if(maxx2==x)a[i].id2=1;
		else a[i].id2=3;
	}else{
		a[i].id1=3;
		if(maxx2==x)a[i].id2=1;
		else a[i].id2=2;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			maxx1=max(max(x,y),z);
			if(maxx1==x)maxx2=max(y,z);
			else if(maxx1==y)maxx2=max(x,z);
			else maxx2=max(x,y);
			work(i);
		}
		sort(a+1,a+1+n,cmp);
		chu();
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id1]<n/2){
				cnt[a[i].id1]++;
				ans+=a[i].x;
			}else{
				cnt[a[i].id2]++;
				ans+=a[i].y; 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
