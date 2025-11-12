#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
}a[100005];
struct stu{
	int id,mn;
}b[100005];
int c[100005];
bool cmp1(node a,node b){
	if(a.x!=b.x)return a.x>b.x;
	if(a.y!=b.y)return a.y>b.y;
	return a.z>b.z;
}
bool cmp2(node a,node b){
	if(a.y!=b.y)return a.y>b.y;
	return a.x>b.x;
}
bool cmp3(node a,node b){
	return a.x-max(a.y,a.z)>b.x-max(b.y,b.z);
}
bool cmp4(node a,node b){
	return a.y-max(a.x,a.z)>b.y-max(b.x,b.z);
}
bool cmp5(node a,node b){
	return a.z-max(a.x,a.y)>b.z-max(b.x,b.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool f2=0,f3=0;
		long long s1=0,s2=0,s3=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y)f2=1;
			if(a[i].z)f3=1;
			b[i].id=i;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)b[i].mn=1,c[1]++,s1+=a[i].x;
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z)b[i].mn=2,c[2]++,s2+=a[i].y;
			else b[i].mn=3,c[3]++,s3+=a[i].z;
		}
		if(!f2 && !f3){
			sort(a+1,a+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
		}
		else{
			if(c[1]>n/2){
				sort(a+1,a+n+1,cmp3);
				for(int i=n/2+1;i<=c[1];i++){
					s1-=a[i].x;
					if(a[i].y>a[i].z)s2+=a[i].y;
					else s3+=a[i].z;
				}
			}else if(c[2]>n/2){
				sort(a+1,a+n+1,cmp4);
				for(int i=n/2+1;i<=c[2];i++){
					s2-=a[i].y;
					if(a[i].x>a[i].z)s1+=a[i].x;
					else s3+=a[i].z;
				}
			}else if(c[3]>n/2){
				sort(a+1,a+n+1,cmp5);
				for(int i=n/2+1;i<=c[3];i++){
					s3-=a[i].z;
					if(a[i].x>a[i].y)s1+=a[i].x;
					else s2+=a[i].y;
				}
			}
			cout<<s1+s2+s3<<"\n";
		}
	}
	return 0;
}
