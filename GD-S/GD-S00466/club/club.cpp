#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,y,z;
}a[100010];
bool cmp1(int x,int y){
	return min(a[x].x-a[x].y,a[x].x-a[x].z)>min(a[y].x-a[y].y,a[y].x-a[y].z);
}
bool cmp2(int x,int y){
	return min(a[x].y-a[x].x,a[x].y-a[x].z)>min(a[y].y-a[y].x,a[y].y-a[y].z);
}
bool cmp3(int x,int y){
	return min(a[x].z-a[x].y,a[x].z-a[x].x)>min(a[y].z-a[y].y,a[y].z-a[y].x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		int v[5][100100],cnt1=0,cnt2=0,cnt3=0;
		memset(v,0,sizeof(v));
		a[0]={-1,-1,-1};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)v[1][++cnt1]=i;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)v[2][++cnt2]=i;
			else v[3][++cnt3]=i;
		}
		sort(v[1]+1,v[1]+cnt1+1,cmp1);
		sort(v[2]+1,v[2]+cnt2+1,cmp2);
		sort(v[3]+1,v[3]+cnt3+1,cmp3);
		int i1=0,i2=0,i3=0;
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
		while(i1<n/2&&i2<n/2&&i3<n/2&&i1+i2+i3<n){
			if(a[v[1][i1+1]].x>=a[v[2][i2+1]].y&&a[v[1][i1+1]].x>=a[v[3][i3+1]].z){
				ans+=a[v[1][++i1]].x;
			}
			else if(a[v[2][i2+1]].y>=a[v[1][i1+1]].x&&a[v[2][i2+1]].y>=a[v[3][i3+1]].z){
				ans+=a[v[2][++i2]].y;
			}
			else if(a[v[3][i3+1]].z>=a[v[2][i2+1]].y&&a[v[3][i3+1]].z>=a[v[1][i1+1]].x){
				ans+=a[v[3][++i3]].z;
			}
		}
//		cout<<i1<<" "<<i2<<" "<<i3<<"\n";
		if(i1+i2+i3==n){
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		if(i1==n/2){
			for(int i=i2+1;i<=cnt2;i++){
				ans+=a[v[2][i]].y;
			}
			for(int i=i3+1;i<=cnt3;i++){
				ans+=a[v[3][i]].z;
			}
			for(int i=i1+1;i<=cnt1;i++){
				int y=a[v[1][i]].y;
				int z=a[v[1][i]].z;
				if(y>=z)ans+=y;
				else ans+=z;
			}
		}
		if(i2==n/2){
			for(int i=i1+1;i<=cnt1;i++){
				ans+=a[v[1][i]].x;
			}
			for(int i=i3+1;i<=cnt3;i++){
				ans+=a[v[3][i]].z;
			}
			for(int i=i2+1;i<=cnt2;i++){
				int y=a[v[2][i]].x;
				int z=a[v[2][i]].z;
				if(y>=z)ans+=y;
				else ans+=z;
			}
		}
		if(i3==n/2){
			for(int i=i2+1;i<=cnt2;i++){
				ans+=a[v[2][i]].y;
			}
			for(int i=i1+1;i<=cnt1;i++){
				ans+=a[v[1][i]].x;
			}
			for(int i=i3+1;i<=cnt3;i++){
				int y=a[v[3][i]].y;
				int z=a[v[3][i]].x;
				if(y>=z)ans+=y;
				else ans+=z;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
