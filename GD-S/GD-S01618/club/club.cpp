#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z,maxx,vis=1;
};
bool cmp(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y>b.y;
}
bool cmp3(node a,node b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		node a[N];
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxx=max(max(a[i].x,a[i].y),a[i].z);
		}
		sort(a+1,a+n+1,cmp);
		long long cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt<n/2 && a[i].vis==1 && a[i].x==a[i].maxx){
				ans+=a[i].x;
				cnt++;
				a[i].vis=0;
			}
		}
		sort(a+1,a+n+1,cmp2);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt<n/2 && a[i].vis==1 && a[i].y==a[i].maxx){
				ans+=a[i].y;
				cnt++;
				a[i].vis=0;
			}
		}
		sort(a+1,a+n+1,cmp3);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt<n/2 && a[i].vis==1 && a[i].z==a[i].maxx){
				ans+=a[i].z;
				cnt++;
				a[i].vis=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
